#include "SymbolTable.hh"


SymbolTable::SymbolTable(Node* root_node)
{
    this->AST_root = root_node;
    program = new Program();
    root = new Scope(nullptr);
    current = root;

    traverseAST(this->AST_root);
}

SymbolTable::~SymbolTable(){
    if(program != nullptr){
        delete program;
    }
    if(root != nullptr){
        delete root;
    }
}

Node* SymbolTable::traverseAST(Node* current, int depth){
//Pre-order traversal

    if(current == nullptr){
        return nullptr;
    }
    if(current->type == "method dec"){

        std::string returnType  = traverseAST(current->children[0], depth +1 )->value;
        std::string identifierName = traverseAST(current->children[1], depth +1)->value;
        currentMethod = new Method(identifierName, returnType);
        this->put(identifierName, currentMethod);

        (currentClass)->addMethod(identifierName, currentMethod, current);        
        
        this->enterScope();
        traverseAST(current->children[2], depth+1); 
        traverseAST(current->children[3], depth+1); 
        this->exitScope();

        currentMethod = nullptr;
    
    }
    else if( current->type == "Main class"){
        Node* ax = traverseAST(current->children[0]);
        currentClass = new Class(ax->value, "CLASS");

        program->addClass(ax->value,currentClass, current);

        this->put(ax->value, currentClass);

        Variable* this_var = new Variable("this", ax->value);
        currentClass->addVariable("this",this_var, nullptr);

        this->enterScope();
        this->put("this", this_var);

        traverseAST(current->children[1], depth+1);

        this->exitScope();
        currentClass = nullptr;

    }
    else if(current->type == "Class Dec"){

        std::string className = traverseAST(current->children[0])->value;
    
        currentClass = new Class(className, "CLASS");
        this->put(className, currentClass);

        program->addClass(className,currentClass, current);

        Variable* this_var = new Variable("this", className);
        currentClass->addVariable("this",this_var, nullptr);

        this->enterScope();
        this->put("this", this_var);

        traverseAST(current->children[1], depth+1);

        this->exitScope();

        currentClass = nullptr;

    }    
    else if(current->type == "Class Dec EXT"){

        std::string className = traverseAST(current->children[0])->value;
        currentClass = new Class(className, "CLASS");
        this->put(className, currentClass);

        program->addClass(className,currentClass, current);

        Variable* this_var = new Variable("this", className);
        currentClass->addVariable("this",this_var, nullptr);

        this->enterScope();
        this->put("this", this_var);
        traverseAST(current->children[2], depth+1);
        this->exitScope();

        currentClass = nullptr;
    }else if(current->type == "ClassDeclarations"
        || current->type == "VarDeclarations"
        || current->type == "MethodDeclarations"
        || current->type == "FunctionBody"
        || current->type == "Param_decls"
        || current->type == "class body"
    ){

        for(Node* n : current->children){
            traverseAST(n, depth+1);
        }

    }
    else if(current->type == "Param_decl"){

        std::string varType = traverseAST(current->children[0])->value;
        std::string identifierName = traverseAST(current->children[1])->value;
        currentVariable = new Variable(identifierName, varType);
        this->put(identifierName, currentVariable);
        
        currentMethod->addParameter(identifierName, currentVariable, current);

    }
    else if(current->type == "VarDeclaration" ){

        std::string varType = traverseAST(current->children[0])->value;
        std::string identifierName = traverseAST(current->children[1])->value;
        currentVariable = new Variable(identifierName, varType);
        this->put(identifierName, currentVariable);

        if(currentMethod != nullptr){
           currentMethod->addVariable(identifierName, currentVariable, current);
        }else{
           currentClass->addVariable(identifierName, currentVariable, current);
        }
    }
    else if(current->type == "GOAL"){

        this->enterScope();
        traverseAST(current->children[0], depth+1); 
        traverseAST(current->children[1], depth+1); 
        this->exitScope();

    }

    return current;
}



void SymbolTable::enterScope(){
    current = current->nextChild();
}

void SymbolTable::exitScope(){
    current = current->parentScope;
}

void SymbolTable::put(std::string key, Record *item){
    current->put(key, item);
}

Record* SymbolTable::lookUp(std::string key){
    Record* r =  current->lookUp(key);
    return r;
}

Method* SymbolTable::getMethod(std::string &className,const std::string &methodName)
{
    auto foundClass = this->program->programClasses.find( className)->second;
    
    Method* to_ret = nullptr;
    if(foundClass){

        for(auto method : foundClass->memberMethods){
            if (method.first == methodName) {
                to_ret =  method.second;
                break;
            }
        }
    }
    return to_ret;
}

void SymbolTable::print(){
    current = root;

    std::cout << "\n=============================" << std::endl;
    std::cout << "         Symbol Table" << std::endl;
    std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;

    printf("PROGRAM:\n");
    for(auto const & [s, r] : program->programClasses){
        
        r->print(1);        
    }


}


void SymbolTable::resetTable(){

    root->resetScope();
}






