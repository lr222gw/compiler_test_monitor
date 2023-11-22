#include "SemanticAnalyser.hh"
#include "SymbolTable.hh"
#include "TrashCollector.hh"
#include "errorMandager.hh"
#include <cstddef>
#include <cstdio>
#include <string>
#include <string_view>
#include "defs.hh"

SemanticAnalyser::SemanticAnalyser(Node *AST, SymbolTable *symbolTable)
    : AST_root(AST), symbolTable(symbolTable) 
{ }

std::string printCompLine(std::string a){
    if(RULE_COMPILER_LINE_ERROR_MESSAGE){
    return a;
    }
    else{
        return "";
    }
}

bool SemanticAnalyser::startChecking() 
{
    bool result = true;

    symbolTable->resetTable();
    traverseAST(AST_root);

    if(errorManager::hasError()){
        printf("\nErrors:\n===============================\n");        
        errorManager::presentErrors(); 
        result = false;
    }

    return result ;
}



 
bool SemanticAnalyser::typeChecking(Record* a, Record* b, Node* node){
                
    if(a == nullptr && b == nullptr) {
                
        errorManager::add(Error {std::string(node->children[0]->value+" and "+node->children[1]->value+" are a undefined"),node,printCompLine(std::to_string(__LINE__))});
        
    }
    else if(a == nullptr){ 
        errorManager::add(Error {std::string(node->children[0]->value+" is a undefined E004"),node,printCompLine(std::to_string(__LINE__))});
        
    }else if(b == nullptr){
        errorManager::add(Error {std::string(node->children[1]->value+" is a undefined E005"),node,printCompLine(std::to_string(__LINE__))});
        
    }else if(a->type == TYPE_CLASS || b->type == TYPE_CLASS ){

        if(a->type == TYPE_CLASS && b->type == TYPE_CLASS){
            errorManager::add(Error {std::string("'a' and 'b' WAS OF TYPE CLASS;TEMP COMPILER WARNING"),node,printCompLine(std::to_string(__LINE__))});
            if(a->id != b->id){
                errorManager::add(Error {std::string(node->children[0]->value+" and expression "+expressionToString(node->children[1])+" are of different types"),node,printCompLine(std::to_string(__LINE__))});
            }
        }else if(a->type == TYPE_CLASS){
            if(a->id != b->type){
                errorManager::add(Error {std::string(node->children[0]->value+" and expression "+expressionToString(node->children[1])+" are of different types"),node,printCompLine(std::to_string(__LINE__))});
            }
        }else if(b->type == TYPE_CLASS){
            if(b->id != a->type){
                errorManager::add(Error {std::string(node->children[0]->value+" and expression "+expressionToString(node->children[1])+" are of different types"),node,printCompLine(std::to_string(__LINE__))});
            }
        }else{
            
        }
    }else if(a->type != b->type){           
             
        errorManager::add(Error {std::string(node->children[0]->value+" and expression "+expressionToString(node->children[1])+" are of different types"),node,printCompLine(std::to_string(__LINE__))});
        
        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("\nERROR....\n\n");}
    }
    return true;
}

std::string SemanticAnalyser::expressionToString(Node* node) 
{
    std::string toReturn;

    
    
    if(node){

        if(node->value == TYPE_DOT_LENGTH){
            toReturn = node->children[0]->value + "." + "length" ;

            return toReturn;
        }

        if(node->type == TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP){

            toReturn = node->children[0]->value + "." + node->children[1]->value + "("+expressionToString(node->children[2])+")";

            return toReturn;
        }
        if(node->type == TYPE_PARAMS){
            std::string comma = "";
            for (auto param : node->children) {
                toReturn += comma + param->value; 
                comma = ",";
            }        
            return toReturn;
        }

        if(node->children.empty()){
        toReturn += node->value + " ";    
        }else{
            
            toReturn += expressionToString(node->children[0]);
            toReturn += node->value + " ";
            toReturn += expressionToString(node->children[1]);
        }
    }
    
    return toReturn;
}

std::string SemanticAnalyser::method_signatureToString(Method* method)
{
    auto concat_params = [method](){std::string list,c; for(auto p : method->parameters){list += c + p->variable->type;c=",";}return list;};
    return method->type + " " + method->id + "("+ concat_params() +")";
}


Node* SemanticAnalyser::traverseAST(Node* node, int scope)
{ //Post-order

    Node* left = nullptr;
    Node* right = nullptr;
    Record* left_record = nullptr;
    Record* right_record = nullptr;    
    Method* current_method_record = nullptr;    
    Class* current_class_record = nullptr;    
    if (  node->type == TYPE_GOAL||
        node->type == TYPE_CLASS_DEC||  
        node->type == TYPE_METHOD_DECL || 
        node->type == TYPE_CLASS_DECL_EXT || 
        node->type == TYPE_MAIN_CLASS
    ) {
        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){std::cout << "Entered Scope: " << ++scope << std::endl;}
        symbolTable->enterScope();
    }
            

    if(!node->children.empty()){
    
        if(node->type == TYPE_IDENTIFIER_EQU_EXPRESSION){
            left = traverseAST(node->children.at(0), scope);
            right = traverseAST(node->children.at(1), scope);
            //check if right is a identefier
            if(right->type == TYPE_IDENTIFIER){
                right_record = symbolTable->lookUp(right->value);                
            }//else we put it in a record
            else{
                right_record = TrashCollector::CreateRecord(right->value, right->type);
            }
            left_record = symbolTable->lookUp(left->value);
            if (left_record != nullptr) {
                typeChecking(left_record, right_record, node);
            }
            else{
                errorManager::add(Error {std::string(left->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
        }
        else if(node->type == TYPE_NEW_INT_OB_EXP_CB){ 
                Node* returnNode = TrashCollector::CreateNode(TYPE_INT_ARR, "", node->line);
                ExNullWrong ret;
                ret = checkIfTypeEM(node->children[0], TYPE_INT);
                return returnNode;
        }
        else if(node->type == TYPE_OP_EXPRESSION_CP){
            return traverseAST(node->children[0]);
        }
        else if(node->type == TYPE_EXPRESSION_OB_EXPRESSION_CB){
            //check its left to see that its a int[] identifier
            left = traverseAST(node->children.at(0), scope);
            right = traverseAST(node->children.at(1), scope);
            ExNullWrong ret;
            Node* returnNode = TrashCollector::CreateNode(TYPE_INT,left->value, node->line);
            ret = checkIfType(left, TYPE_INT_ARR);
            if(ret == ExNullWrong::_Null){
                returnNode->type = "null"; //TODOL: NOTE: Vi verkar inte använda detta? Ska det bort? (4 platser)
                errorManager::add(Error {std::string(left->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
            if(ret == ExNullWrong::Wrong){
                returnNode->type = "null";
                errorManager::add(Error {std::string(left->value + " is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            }
            //check its right to see that its a int
            ret = checkIfType(right, TYPE_INT);
            if(ret == ExNullWrong::_Null){
                returnNode->type = "null";
                errorManager::add(Error {std::string(right->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
            else if(ret == ExNullWrong::Wrong){
                returnNode->type = "null";
                errorManager::add(Error {std::string(right->value + " is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            }
            
            return returnNode;
        }
        else if(node->type == TYPE_IF_ELSE || node->type == TYPE_WHILE){
            left = traverseAST(node->children.at(0), scope);
            ExNullWrong ret;
            if(left->type != ""){
                ret = checkIfType(left, TYPE_BOOLEAN);
                if(ret == ExNullWrong::_Null){
                    errorManager::add(Error {std::string(left->value + " doesn't exist"),node,printCompLine(std::to_string(__LINE__))});
                }
                else if(ret == ExNullWrong::Wrong){
                    errorManager::add(Error {std::string(left->value + " is not a bool"),node,printCompLine(std::to_string(__LINE__))});
                }
            }
            for(int i = 1; i < node->children.size(); i++){
                traverseAST(node->children.at(i));
            }
            
        }        
        else if(node->type == TYPE_IDENTIFIER_OB_EXPRESSION_CB_EQU_EXPRESSION){
            left = traverseAST(node->children.at(0), scope);
            Node* middle = traverseAST(node->children.at(1), scope);
            right = traverseAST(node->children.at(2), scope);
            //check left child so its a int[]
            ExNullWrong ret;
            ret = checkIfType(left, TYPE_INT_ARR);//TODOL: can we use checkIfTypeEM?
            if(ret == ExNullWrong::_Null){
                errorManager::add(Error {std::string(left->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
            else if(ret == ExNullWrong::Wrong){
                errorManager::add(Error {std::string(left->value + " is wrong data type"),node,printCompLine(std::to_string(__LINE__))});
            }
            //check that middle child is a int
            ret = checkIfType(middle, TYPE_INT);//TODOL: can we use checkIfTypeEM?
            if(ret == ExNullWrong::_Null){
                errorManager::add(Error {std::string(middle->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
            else if(ret == ExNullWrong::Wrong){
                errorManager::add(Error {std::string(middle->value + " is wrong data type"),node,printCompLine(std::to_string(__LINE__))});
            }
            //check right child
            ret = checkIfType(right, TYPE_INT);
            if(ret == ExNullWrong::_Null){
                errorManager::add(Error {std::string(right->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
            }
            else if(ret == ExNullWrong::Wrong){
                errorManager::add(Error {std::string(right->value + " is wrong data type"),node,printCompLine(std::to_string(__LINE__))});
            }
        }
        else if(node->type == TYPE_EXCLAIMATION_EXPRESSION){
            Node* returnNode = traverseAST(node->children[0],scope);
            if(checkIfType(returnNode, TYPE_BOOLEAN) != ExNullWrong::Exist){
                errorManager::add(Error {std::string(returnNode->value + " is not a boolean"),node,printCompLine(std::to_string(__LINE__))});
            };
            return returnNode;
        }
        else if(node->type == TYPE_OPERATOR){
            left = traverseAST(node->children[0],scope);
            right = traverseAST(node->children[1],scope);
            Node* returnNode = TrashCollector::CreateNode("","", node->line);
            returnNode->value = left->value + node->value + right->value;
            returnNode->line = node->line;
            left->line = node->line;
            right->line = node->line;
            if(node->value == OPR_AND || node->value == OPR_OR){ // OPR_OR = '||' , OPR_AND = '&&'
                //check both sides are boolean, 'checkIfTypeEM' handles the error messages...
                returnNode->type = TYPE_BOOLEAN;
                checkIfTypeEM(left, TYPE_BOOLEAN);
                checkIfTypeEM(right, TYPE_BOOLEAN);

            }
            else if(node->value == OPR_EQUEQU){ // OPR_EQUEQU = '=='
                returnNode->type = TYPE_BOOLEAN;
                if(left->type != right->type){
                    errorManager::add(Error {std::string(left->type + ":" + left->value + 
                    " is not the same typ as " + right->type + ":" + right->value ),node,printCompLine(std::to_string(__LINE__))});                    
                }

            }
            else if(node->value == OPR_LESS_THAN || node->value == OPR_MORE_THAN){ // OPR_LESS_THAN = '<' , OPR_MORE_THAN = '>'                
                //check both sides are int, 'checkIfTypeEM' handles the error messages...
                returnNode->type = TYPE_BOOLEAN;
                checkIfTypeEM(left, TYPE_INT);
                checkIfTypeEM(right, TYPE_INT);
            }
            else{//+,-,*,/
                //check both sides are int, 'checkIfTypeEM' handles the error messages...
                returnNode->type = TYPE_INT;
                checkIfTypeEM(left, TYPE_INT);
                checkIfTypeEM(right, TYPE_INT);
            }
            return returnNode;
        }
        else if(node->type == TYPE_METHOD_DECL){
            //check so return has the same
            left = traverseAST(node->children.at(0), scope);
            int return_node = node->children.at(3)->children.size() - 1;
            right = traverseAST(node->children.at(3)->children.at(return_node)->children.at(0), scope);
            
            if(left->value == TYPE_VOID){
                //se that we don't return anything
                if(right->value != TYPE_VOID){ // No return type
                    errorManager::add(Error {std::string(node->value + " is a void, and has a return"),node,printCompLine(std::to_string(__LINE__))});
                }
            }
            else{
               
               left_record = TrashCollector::CreateRecord(traverseAST(node->children.at(1), scope)->value, left->value);
               if(right->type == TYPE_IDENTIFIER){
                   right_record = symbolTable->lookUp(right->value);
               }else {
                   right_record = TrashCollector::CreateRecord("return", right->type);
               }
               
               typeCheck_methodReturnTypes(left_record, right_record, node);
            }
            
            //traverse the function body
            traverseAST(node->children[3]); 
            
            
        }
        else if(node->type == TYPE_FUNCTIONBODY){
            for(auto n : node->children){
                //function body: VarDeclarations, Statements,...
                traverseAST(n, scope);
            }
        }
        else if(node->type == TYPE_STATEMENTS){
            for(auto n : node->children){
                //For every statement in function body...
                traverseAST(n, scope);
            }
        }
        else if(node->type == TYPE_NEW_IDENTIFIER_OP_PARAMS_CP){        
            Node* returnNode = TrashCollector::CreateNode("Class", node->value, node->line); //NOTE: Ska detta vara "Class"? (Vi har inga andra Noder som har typen "Class") 
            if(ExNullWrong::Exist == checkIfType(node->children[0], TYPE_CLASS)){
                return node->children[0];
            }else{
                errorManager::add(Error {std::string(node->children[0]->value + " is not a valid Class"),node,printCompLine(std::to_string(__LINE__))});
            }
            return returnNode;
        }
        else if(node->type == TYPE_VAR_DOT_IDENTIFIER_OP_PARAMS_CP){
            // Function Call
            auto nodeClass = traverseAST(node->children[0],scope);
            Node* to_ret = TrashCollector::CreateNode("", "", node->line);
      
            Record* classAsMember_type = symbolTable->lookUp(nodeClass->value);          
            Record* A = nullptr;

            if(classAsMember_type){                
                if (classAsMember_type->type == TYPE_CLASS){
                    current_class_record = dynamic_cast<Class*>(classAsMember_type);
                }
                else if(classAsMember_type->id != SPECIAL_ID_THIS){ // SPECIAL_ID_THIS = 'this'
                    A = (symbolTable->lookUp(classAsMember_type->id));                    
                    current_class_record = dynamic_cast<Class*>(symbolTable->lookUp(A->type));

                    if(!current_class_record){
                        errorManager::add(Error {std::string("Class "+A->type + " is undefined, cant call "+node->children[1]->value+ " on undefined class"),node,printCompLine(std::to_string(__LINE__))});
                    }
                
                }else{
                    current_class_record = dynamic_cast<Class*>(symbolTable->lookUp(classAsMember_type->type));
                    if(!current_class_record){                                        
                        errorManager::add(Error {std::string("Class "+classAsMember_type->type + " is undefined, cant call "+node->children[1]->value+ " on undefined class"),node,printCompLine(std::to_string(__LINE__))});
                    }
                }
                
                if(current_class_record){                    
                    current_method_record = current_class_record->lookUpMethod(node->children[1]->value);
                }                    
                    
                if(current_method_record){
                    to_ret->type = current_method_record->type; 
                    to_ret->value = current_method_record->id;

                    if(node->children[2]->children.size() == current_method_record->parameters.size()){
                        this->typeCheck_methodArguments(&node->children[2]->children, &current_method_record->parameters, node, current_method_record);
                        

                    }else{                    
                        errorManager::add(Error {std::string("Parameter missmatch when calling "+ method_signatureToString(current_method_record)
                        +". Function takes " + std::to_string(current_method_record->parameters.size())
                        +" not " + std::to_string(node->children[2]->children.size()) + " arguments"),node,printCompLine(std::to_string(__LINE__))});
                    }
                }else {

                    errorManager::add(Error {std::string("function "+ classAsMember_type->type + "." + node->children[1]->value + " is undefined"),node,printCompLine(std::to_string(__LINE__))});
                }                    
            }
                        
            return to_ret;
        }
        else if(node->value == TYPE_DOT_LENGTH){//TODO_ : should we change so node->type = node->value? (must be changed in parser.yy then...)
            left = traverseAST(node->children[0], scope);
            Node* returnNode =  TrashCollector::CreateNode(TYPE_INT,left->value, node->line);
            ExNullWrong ret;
            ret = checkIfType(left, TYPE_INT_ARR);
            if(ret != ExNullWrong::Exist){
                errorManager::add(Error {std::string(left->value + " is undefined or wrong"),node,printCompLine(std::to_string(__LINE__))});
                if(ret == ExNullWrong::Wrong){
                    returnNode->type = left->type;
                }
                else{
                    returnNode->type = TYPE_INT;
                }
            }
            else{
                returnNode->type = TYPE_INT;
            }
            return returnNode;
        }       
        else{
            if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("NODE.value: %s, node.type: %s ,node.NrOfChildren: %s\n",node->value.c_str(), node->type.c_str(),std::to_string(node->children.size()).c_str());}
            for(auto n : node->children){
                traverseAST(n, scope);
            }
        }        
    }
    else if(node->type == TYPE_IDENTIFIER){ //Makes sure we return valid node to compare with if identifier is a class...
        if(ExNullWrong::Exist == checkIfType(node, TYPE_CLASS)){
            auto classNode = symbolTable->lookUp(node->value);
            Node* n = TrashCollector::CreateNode(classNode->type, classNode->id,node->line);            
            return n;
        }
        else if(ExNullWrong::Exist != checkIfType(node, TYPE_METHOD_DECL)){
            auto idNode = symbolTable->lookUp(node->value);
            if(idNode){
                Node* n = TrashCollector::CreateNode(idNode->type, idNode->id, node->line);            
                return n;
            }else{
                errorManager::add(Error {std::string(node->value + " is undefined."),node,printCompLine(std::to_string(__LINE__))});
            }
        }
    }else if(node->type == TYPE_THIS){ //Makes sure we return valid node to compare with if identifier is a class... //NOTE: Is this comment wrong
        if(ExNullWrong::Exist == checkIfType(node, TYPE_CLASS)){
            Record* classAsMember_type = symbolTable->lookUp(node->value);    
            current_class_record = dynamic_cast<Class*>(symbolTable->lookUp(classAsMember_type->type));
            if(!current_class_record){                                        
                errorManager::add(Error {std::string("Class "+classAsMember_type->type + " is undefined, cant call "+node->children[1]->value+ " on undefined class"),node,printCompLine(std::to_string(__LINE__))});
            }
            auto classNode = symbolTable->lookUp(node->value);
            Node* n = TrashCollector::CreateNode(classNode->type, classNode->id,node->line);            
            return n;
        } //else; node will be returned in the end of fuction...
    }
    else {
        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("NODE: %s\n",node->value.c_str());}        
    }

    if (node->type == TYPE_GOAL||
        node->type == TYPE_CLASS_DEC||  
    node->type == TYPE_METHOD_DECL || 
    node->type == TYPE_CLASS_DECL_EXT || 
    node->type == TYPE_MAIN_CLASS
    ) {
        
        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){std::cout << "Exit Scope: " << scope << std::endl;}
        symbolTable->exitScope();
    }
        

    return node;

}

ExNullWrong SemanticAnalyser::checkIfTypeEM(Node* node, std::string type){
    Record* testRec;
    //check for a variable
    if(node->type == TYPE_IDENTIFIER){
        testRec = symbolTable->lookUp(node->value);
        if(testRec == nullptr){
            errorManager::add(Error {std::string(node->value + ": is undefiend"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::_Null;
        }
        else if(testRec->type == type){
            return ExNullWrong::Exist;
        }
        else{
            errorManager::add(Error {std::string(node->value + ": is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::Wrong;
        }
    }else if(node->type == TYPE_EXCLAIMATION_EXPRESSION){ 
        auto n = traverseAST(node->children[0]);
        if(n->type == TYPE_IDENTIFIER){
            testRec = symbolTable->lookUp(n->value);
            if(testRec->type == type){
                return ExNullWrong::Exist;
            }
            else{
                errorManager::add(Error {std::string(node->value + ": is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
                return ExNullWrong::Wrong;
            }
        }
        if(n->type == type){
            return ExNullWrong::Exist;
        }
        else{
            errorManager::add(Error {std::string(node->value + ": is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::Wrong;
        }
    }
    else if(node->type == TYPE_THIS){ 
        testRec = symbolTable->lookUp(node->value);
        
        if(testRec == nullptr){
            errorManager::add(Error {std::string(node->value + ": is undefiend"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::_Null;
        }else{
            testRec = symbolTable->lookUp(testRec->type);
        }
        
        if(testRec->type == type){
            return ExNullWrong::Exist;
        }
        else{            
            errorManager::add(Error {std::string(node->value + ": is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::Wrong;
        }
    }
    else{
        //check for a data type
        if(node->type == type){
            return ExNullWrong::Exist;
        }
        else{
            errorManager::add(Error {std::string(node->value + ": is of wrong type"),node,printCompLine(std::to_string(__LINE__))});
            return ExNullWrong::Wrong;
        }
    }
}
ExNullWrong SemanticAnalyser::checkIfType(Node* node, std::string type){
    Record* testRec;
    //check for a variable
    if(node->type == TYPE_IDENTIFIER){
        testRec = symbolTable->lookUp(node->value);
        if(testRec == nullptr){
            return ExNullWrong::_Null;
        }
        else if(testRec->type == type){
            return ExNullWrong::Exist;
        }
        else{
            return ExNullWrong::Wrong;
        }
    }else if(node->type == TYPE_EXCLAIMATION_EXPRESSION){
        auto n = traverseAST(node->children[0]);
        //testRec = traverseAST(node->children[0]);
        if(n->type == TYPE_IDENTIFIER){
            testRec = symbolTable->lookUp(n->value);
            if(testRec->type == type){
                return ExNullWrong::Exist;
            }
            else{
                return ExNullWrong::Wrong;
            }
        }
        if(n->type == type){
            return ExNullWrong::Exist;
        }
        else{
            return ExNullWrong::Wrong;
        }
    }
    else if(node->type == TYPE_THIS){
        testRec = symbolTable->lookUp(node->value);
        
        if(testRec == nullptr){
            return ExNullWrong::_Null;
        }else{
            testRec = symbolTable->lookUp(testRec->type);
        }
        
        if(testRec->type == type){
            return ExNullWrong::Exist;
        }
        else{
            return ExNullWrong::Wrong;
        }
    }
    else{
        //check for a data type
        if(node->type == type){
            return ExNullWrong::Exist;
        }
        else{
            return ExNullWrong::Wrong;
        }
    }
}


void SemanticAnalyser::typeCheck_methodReturnTypes(Record* a, Record* b, Node* node) 
{
    if(a == nullptr && b == nullptr) {
        errorManager::add(Error {std::string(node->children[0]->value+" and "+node->children[1]->value+" are a undefined " ),node,printCompLine(std::to_string(__LINE__))});
    }
    else if(a == nullptr){ 
        errorManager::add(Error {std::string(node->children[0]->value+" is a undefined "),node,printCompLine(std::to_string(__LINE__))});
    }else if(b == nullptr){
        errorManager::add(Error {std::string(node->children[1]->value+" is a undefined "),node,printCompLine(std::to_string(__LINE__))});
    }else if(a->type != b->type){                   
        errorManager::add(Error {std::string("Method: " + a->id + " and its "+ b->id +" are of different types"),node,printCompLine(std::to_string(__LINE__))});
        if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("\nERROR....\n\n");}
    }
}

void SemanticAnalyser::typeCheck_methodArguments(std::vector<Node*>* a, std::vector<Param*>* b, Node* node, Method* method) 
{
    int i = 0;
    std::string type;
    std::string name;
    for(; i < b->size(); i++){
        
        if(a->at(i)->type == TYPE_OPERATOR ){
            Node* temp = traverseAST(a->at(i));
            type = temp->type;
            name = temp->value;
        }else if(a->at(i)->type != TYPE_INT && a->at(i)->type != TYPE_BOOLEAN ){
            Node* temp = traverseAST(a->at(i));
            Record* r_temp = symbolTable->lookUp(temp->value);
            type = r_temp->type;
            name = r_temp->id;
            if(type == "CLASS"){
                type = name;
            }
        }else{
            type = a->at(i)->type;
            name = a->at(i)->id;
        }

        if(b->at(i)->variable->type != type){
            if(name == type){ //NOTE: this is bad but i'm lazy now. This is only true when type was 'CLASS'... bugprone
                errorManager::add(Error {std::string("Function "+(method_signatureToString(method)) 
                + " parameter number " + std::to_string(i+1) + " requires type " + b->at(i)->variable->type 
                + ", supplied argument was a Class of type " + type
                ),node,printCompLine(std::to_string(__LINE__))});
            }else{
                errorManager::add(Error {std::string("Function "+(method_signatureToString(method)) 
                + " parameter number " + std::to_string(i+1) + " requires type " + b->at(i)->variable->type 
                + ", supplied variable '" + name +"' is of type " + type
                ),node,printCompLine(std::to_string(__LINE__))});
            }
        }
    }
}