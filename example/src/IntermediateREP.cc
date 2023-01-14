#include "IntermediateREP.hh"
#include "SymbolTable.hh"
#include "defs.hh"
#include <cstddef>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
IntermediateRepresentation::IntermediateRepresentation(Node *AST, SymbolTable *ST)
: nameId(0)
{    
    this->symbolTable = ST;
    symbolTable->resetTable();
    AST_to_CFG_roots(AST, "No Class");
    std::string CC = "";
    bool first = false;
    
    symbolTable->enterScope();
    for(const auto& cfg: CFGs){
        if(CC != cfg->getClass){

            if(!first){ first = true;}
            else{
                symbolTable->exitScope();
            }

            symbolTable->enterScope();
            CC = cfg->getClass;
        }
        symbolTable->enterScope();
        currentMethod = dynamic_cast<Method*>(symbolTable->lookUp(cfg->fName));
        traverseAST(cfg->AST_subroot, cfg->rootBlock);
        symbolTable->exitScope();

    }
    symbolTable->exitScope();
}

void IntermediateRepresentation::printme()
{
    //for(auto cfg : CFGs){
    //    printf("Method%s\n", cfg.fName.c_str());
    //    printme_rec(cfg.rootBlock, 0);
    //} 
}

void IntermediateRepresentation::printme_rec(BasicBlock* ptr, int spaces)
{
    std::string _spaces ;
    for(int i =0 ; i < spaces; i++){_spaces+=" ";}
    
    

    if(ptr){

         for(int i = 0; i < ptr->tacInstructions.size(); i++){
            ptr->tacInstructions[i]->print();
        }
        printf("%s%s:falseExit,%s\n",_spaces.c_str(), ptr->name.c_str(), ptr->falseExit ? ptr->falseExit->name.c_str() : "null"); 
       
        if(ptr->falseExit){
            printme_rec(ptr->falseExit, spaces + 4);            
        }

        printf("%s%s:trueExit, %s\n",_spaces.c_str(), ptr->name.c_str(), ptr->trueExit  ? ptr->trueExit->name.c_str()  : "null");
        if(ptr->trueExit){
            printme_rec(ptr->trueExit, spaces + 4); 
        }

    }
     
} 


void IntermediateRepresentation::AST_to_CFG_roots(Node* node, std::string currentclass)
{
    static int ID_counter=0;
    if (node->type == TYPE_CLASS_DEC||   
        node->type == TYPE_CLASS_DECL_EXT || 
        node->type == TYPE_MAIN_CLASS)
        {
            currentclass = node->children.at(0)->value;
        }
    if(node->type == TYPE_METHOD_DECL){

        BasicBlock* b = new BasicBlock();
        
        b->name="root_"+std::to_string(ID_counter++);
        b->node = node;
        
        CFGs.push_back(new CFG{node->children[1]->value, b, node, currentclass});
        
    }
    for(auto n : node->children){
        AST_to_CFG_roots(n, currentclass);
    }
}

NodeBlock* IntermediateRepresentation::traverseAST(Node* node, BasicBlock* _currentBlock){
    
    
    NodeBlock* ret = new NodeBlock{"", node, _currentBlock};
    
    static int ID_counter=0;
    static int IFELSE_ID_counter=0;
    static int WHILE_ID_counter=0;

    if(node->type == TYPE_METHOD_DECL){
        ret->block= _currentBlock;
        for(auto *c : node->children){

            ret = traverseAST(c, ret->block);
        }
    }
    else if(node->type == TYPE_STATEMENTS || node->type == TYPE_OM_STATEMENT_CM ){
        
        ret->block= _currentBlock;
        for(auto *c : node->children){

            ret = traverseAST(c, ret->block);     
        }
    
    }
    else if(node->type == TYPE_IF_ELSE){


        ///Create Basic Block for True and False Scenarios
        NodeBlock* b_true = new NodeBlock(); 
        NodeBlock* b_false = new NodeBlock();
        b_true->block = new BasicBlock();        
        b_true->node  = node->children[1];
        b_true->block->name="TRUE_B"+std::to_string(IFELSE_ID_counter++);

        b_false->block = new BasicBlock();
        b_false->node = node->children[2];
        b_false->block->name="FALSE_B"+std::to_string(IFELSE_ID_counter++);

        NodeBlock* end_if_block = new NodeBlock();
        end_if_block->block = new BasicBlock();//end_if_block
        end_if_block->block->name="JOIN_B_"+std::to_string(IFELSE_ID_counter++);

        
        //Get IR 
        auto _true_case  = traverseAST( node->children[1], b_true->block);                
        auto _false_case = traverseAST( node->children[2], b_false->block);        

        _currentBlock->trueExit  = b_true->block;
        _currentBlock->falseExit = b_false->block; 

        _true_case->block->trueExit     = end_if_block->block; //Blocks should connect
        _false_case->block->trueExit    = end_if_block->block; //Blocks should connect   

        _true_case->block->tacInstructions.push_back(new UnCondJump(end_if_block->block->name)); 
        _false_case->block->tacInstructions.push_back(new UnCondJump(end_if_block->block->name));         

        //!_currentBlock->tacInstructions.push_back(new CondJump("goto", node->children.at(0)->value, _currentBlock->falseExit->name));
        _currentBlock->tacInstructions.push_back(new CondJump(traverseAST(node->children[0], _currentBlock)->TAC_address_name, _currentBlock->falseExit->name));
        ret->block = end_if_block->block;
        ret->node = end_if_block->node;

        
            
    }
    else if(node->type == TYPE_WHILE){
        //create blocks
        NodeBlock* while_B = new NodeBlock;
        NodeBlock* true_B = new NodeBlock;
        NodeBlock* false_B = new NodeBlock;

        //give em info
        while_B->block = new BasicBlock();        
        while_B->node  = node;
        while_B->block->name= "W_HEAD_B_"+std::to_string(WHILE_ID_counter++);
        true_B->block = new BasicBlock();        
        true_B->node  = node->children[1];
        true_B->block->name= "W_BODY_B_"+std::to_string(WHILE_ID_counter++);
        false_B->block = new BasicBlock();        
        false_B->block->name = "W_JOIN_B_"+std::to_string(WHILE_ID_counter++);
        //don't know what to give false?
        true_B->block->trueExit = while_B->block;

        //go trough true
        auto _true_case = traverseAST(node->children[1], true_B->block); 
        
        //Connect while header to whilebody (true_B) and the joinblock (false_B)
        while_B->block->trueExit = true_B->block;
        while_B->block->falseExit = false_B->block;
        
        //set last block exit to this //no idea if this work
        _true_case->block->trueExit = while_B->block;    
        _true_case->block->tacInstructions.push_back(new UnCondJump(while_B->block->name)); 
        

        //!while_B->block->tacInstructions.push_back(new CondJump("goto", node->children.at(0)->value, ""));//currentBlock->falseExit->name));
        while_B->block->tacInstructions.push_back(
            new CondJump(
                traverseAST(node->children[0], while_B->block)->TAC_address_name,                 
                while_B->block->falseExit->name));

        //set so current block exit is exit
        _currentBlock->trueExit = while_B->block;
        

        ret = false_B;
            
        //return false_B;
        

    }else if(node->type == TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP){
            //get this // or the other temp
            std::string temp_Name = genName();
            std::string this_name = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
            

            //get the parameters
            _currentBlock->tacInstructions.push_back(new Parameter(this_name));  
            
            //Push arguments (parameters) TACs 
            for(auto _param : node->children[2]->children){
                _currentBlock->tacInstructions.push_back(new Parameter(traverseAST(_param, _currentBlock)->TAC_address_name));                            
            } 

            //get funciton name
            std::string funcName = traverseAST(node->children.at(1), _currentBlock)->TAC_address_name;
            
            auto var = (symbolTable->lookUp(this_name));
            Class* thisClass = dynamic_cast<Class*>(symbolTable->lookUp(var->type));
            auto theType = thisClass->lookUpMethod(funcName)->type;
            //std::string theType = symbolTable->lookUp(funcName)->type;
            
            auto currentVariable = new Variable(temp_Name, theType);
            symbolTable->put(temp_Name, currentVariable);
            currentMethod->addVariable(temp_Name, currentVariable, node);

            _currentBlock->tacInstructions.push_back(
                new MethodCall(temp_Name,
                funcName, 
                std::to_string(node->children[2]->children.size() + 1))); // Add one extra parameter to pass class instans...

            ret->TAC_address_name = temp_Name;

    }
    else if(node->type == TYPE_IDENTIFIER_EQU_EXPRESSION ){
        std::string LS      = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
        auto  RS_nodeBlock  = traverseAST(node->children.at(1),_currentBlock);
        std::string RS      = RS_nodeBlock->TAC_address_name;
                    
        _currentBlock->tacInstructions.push_back(new Copy(LS, RS));         
    
    }
    else if(node->type == TYPE_IDENTIFIER_OB_EXPRESSION_CB_EQU_EXPRESSION){
        // std::string temp_name = genName();

        // auto currentVariable = new Variable(temp_name, TYPE_INT);
        // symbolTable->put(temp_name, currentVariable);
        // currentMethod->addVariable(temp_name, currentVariable, node);

        //travese to add the subset of the condition TACs 
        auto identifier = traverseAST(node->children[0], _currentBlock);
        auto index      = traverseAST(node->children[1], _currentBlock);
        auto value      = traverseAST(node->children[2], _currentBlock);
                    
        _currentBlock->tacInstructions.push_back(new ArrayCopy(identifier->TAC_address_name, value->TAC_address_name, index->TAC_address_name));         
    
    }
    else if(node->type == TYPE_EXCLAIMATION_EXPRESSION){
        std::string temp_name = genName();

        auto currentVariable = new Variable(temp_name, TYPE_BOOLEAN);
        symbolTable->put(temp_name, currentVariable);
        currentMethod->addVariable(temp_name, currentVariable, node);

        //travese to add the subset of the condition TACs 
        auto res = traverseAST(node->children[0], _currentBlock);

        //Create unaryExpression TAC and push it to the block
        auto tac = new Unary_expression(temp_name, "!", res->TAC_address_name);
        _currentBlock->tacInstructions.push_back(tac);

        //Return the temp_name to be used by the caller
        ret->TAC_address_name = temp_name;
    }
    else if(node->type == TYPE_EXPRESSION_OB_EXPRESSION_CB){ //TODO: Check if this is OK and if output is ok. Simon
        std::string temp_name = genName();
        //travese to add the subset of the condition TACs 
        auto currentVariable = new Variable(temp_name, TYPE_INT);
        symbolTable->put(temp_name, currentVariable);
        currentMethod->addVariable(temp_name, currentVariable, node);

        auto identifier = traverseAST(node->children[0], _currentBlock);
        auto index      = traverseAST(node->children[1], _currentBlock);

        //Create ArrayAccess TAC and push it to the block
        auto tac = new ArrayAccess(temp_name, identifier->TAC_address_name, index->TAC_address_name);
        _currentBlock->tacInstructions.push_back(tac);

        //Return the temp_name to be used by the caller
        ret->TAC_address_name = temp_name;
    }    
    else if(node->type == TYPE_SYSTEM_PRINT){
        // TODO: Kolla om simon är nöjd med det här
        //std::string temp_name_out_system = genName();
        //temp_name_out_system = "system.out"
        
        std::string temp_name = genName();        
        std::string LS = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;

        //_currentBlock->tacInstructions.push_back(new Copy(temp_name_out_system, "system.out")); //Tänker att system.out är en special variabel
        //NOTE: Vet inte hur vi skulle kunna dela upp "system.out" till två olika? Alternativt skippa och köra något i stil med: 
        // system_out_printl <-- som en enda funktion... (Kolla BNF från uppgift 1 ... PRINT ligger som en egen statement...)
        //_currentBlock->tacInstructions.push_back(new Parameter(temp_name_out_system));
        _currentBlock->tacInstructions.push_back(new Parameter("system"));
        _currentBlock->tacInstructions.push_back(new Parameter(LS));

        _currentBlock->tacInstructions.push_back(new PrintCall());

        //_currentBlock->tacInstructions.push_back(new Copy(LS, RS));

        // ret->TAC_address_name = temp_name;
        //return ret;
    }    
    else if(node->type == TYPE_NEW_IDENTIFIER_OP_PARAMS_CP){

        std::string temp_name = genName();
        std::string LS = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
        _currentBlock->tacInstructions.push_back(new New(temp_name, LS));

        auto currentVariable = new Variable(temp_name, node->children.at(0)->value);
        symbolTable->put(temp_name, currentVariable);
        currentMethod->addVariable(temp_name, currentVariable, node);

        ret->TAC_address_name = temp_name;
        //return ret;
    }
     else if(node->type == TYPE_NEW_INT_OB_EXP_CB){

        std::string temp_name = genName();
        std::string LS = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
        _currentBlock->tacInstructions.push_back(new New_Array(temp_name, TYPE_INT_ARR, LS));

        auto currentVariable = new Variable(temp_name, TYPE_INT);
        symbolTable->put(temp_name, currentVariable);
        currentMethod->addVariable(temp_name, currentVariable, node);

        ret->TAC_address_name = temp_name;
        //return ret;
    }
    else if(node->type == TYPE_RETURN){


        std::string LS = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
        _currentBlock->tacInstructions.push_back(new theReturn(LS));
    }
    else if(node->type == TYPE_OPERATOR){

        std::string name = genName();

        std::string LS = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;
        std::string RS = traverseAST(node->children.at(1),_currentBlock)->TAC_address_name;
        _currentBlock->tacInstructions.push_back(new Expression(LS, node->value, RS, name));

        std::string theType = TYPE_INT;
        if(node->value == OPR_AND || 
        node->value == OPR_EQUEQU || 
        node->value == OPR_LESS_THAN ||
        node->value == OPR_MORE_THAN||
        node->value == OPR_OR){
            theType = TYPE_BOOLEAN;
        }

        auto currentVariable = new Variable(name, theType);
        symbolTable->put(name, currentVariable);
        currentMethod->addVariable(name, currentVariable, node);

        ret->TAC_address_name = name;
        //return ret;
    }
    else if(node->value == TYPE_DOT_LENGTH){

        std::string name = genName();
        std::string identifier = traverseAST(node->children.at(0),_currentBlock)->TAC_address_name;

        _currentBlock->tacInstructions.push_back(new lenght(name, identifier));
        //symbolTable->put(name, new Variable(name, TYPE_INT));

        auto currentVariable = new Variable(name, TYPE_INT);
        symbolTable->put(name, currentVariable);
        currentMethod->addVariable(name, currentVariable, node);

        ret->TAC_address_name = name;
    }
    else if(node->type == TYPE_IDENTIFIER){
        ret->TAC_address_name = node->value;
    }
    else if(node->type == TYPE_INT || node->type == TYPE_BOOLEAN){
        ret->TAC_address_name = "$"+ node->value; // Constants should have a "$" symbol infront, according to lecture slides
    }
    else if(node->type == TYPE_EXPRESSION_OB_EXPRESSION_CB){//stuff with array
        ret->TAC_address_name = node->children.at(0)->value + "["+ traverseAST(node->children.at(1), _currentBlock)->TAC_address_name +"]";
    }
    else if(node->type == TYPE_THIS){
        ret->TAC_address_name = SPECIAL_ID_THIS;
    }
    else if(node->type == TYPE_VOID){
        ret->TAC_address_name = TYPE_VOID;
    }
    else{

        auto temp = _currentBlock;
        ret->block = _currentBlock;
        for(auto *c : node->children){
            ret = traverseAST(c, ret->block);
        }
    }
        
    
    
    //return ret; 
    return ret;
}




void IntermediateRepresentation::generate_CFG()
{
    std::ofstream outStream;
    outStream.open("CFGs.dot");

    int count = 0;
    outStream << "digraph L{" << std::endl;
    outStream << "node [shape=box fontname=Arial];" << std::endl;
    //outStream << "graph [splines=ortho];" << std::endl; //Om vi ändrar oss...
    for(auto cfg : this->CFGs){
        outStream << "subgraph cluster_" << cfg->fName << " {" << std::endl;        
        outStream << "label = \""<< cfg->fName <<"\";" << std::endl;        
        generate_CFG_content(*cfg->rootBlock, count, &outStream);
        outStream << "}" << std::endl;        
    }
    outStream << "}" << std::endl;
    outStream.close();
}

std::vector<CFG*>* IntermediateRepresentation::getCFGs()
{
    return &CFGs;
}

void IntermediateRepresentation::generate_CFG_content(BasicBlock &basicBlock, int count, ofstream *outStream) {                
    
    *outStream << "n" << basicBlock.name << " [label=\"Block:" << basicBlock.name << "\\n";
    
    for(auto *tac : basicBlock.tacInstructions){
        *outStream<< tac->to_String() + "\\l";
    }
    *outStream<< "\"];" << endl;
    
    static std::vector<std::string> visited;
    //see if we have visited nodes            
    for(auto v : visited){
        if(basicBlock.name == v){
            return;
        }
    }
    //add it to the list
    visited.push_back(basicBlock.name);

    if(basicBlock.trueExit){
        generate_CFG_content(*basicBlock.trueExit, count + 1, outStream);
        *outStream << "n" << basicBlock.name << " -> n" << basicBlock.trueExit->name;
        *outStream << "[label=\"true\"];"<< endl;
    }

    if(basicBlock.falseExit){
        generate_CFG_content(*basicBlock.falseExit, count + 1, outStream);
        *outStream << "n" << basicBlock.name << " -> n" << basicBlock.falseExit->name << endl;
        *outStream << "[label=\"false\"];"<< endl;
    }
    
}


std::string IntermediateRepresentation::genName(){
    std::string ret = "temp_" + std::to_string(nameId++);
    return ret;
}
