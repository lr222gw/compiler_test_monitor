#include "Method.hh"
#include "SymbolTable.hh"


Param::~Param()
{
    delete variable;
}
Method::~Method()
{
    
    for (auto p : parameters) {
        delete p;
    }
    
    for (auto itr = variables.begin(); itr != variables.end(); itr++  ) {
        delete itr->second;
    }
    
}

Method::Method(std::string name, std::string returnType)
: Record(name, returnType)
{}

void Method::addVariable(std::string name, Record *variable, Node* nodePtr){
    int prev_size = variables.size(); 
    variables.insert(std::make_pair(name, dynamic_cast<Variable*>(variable)));
    if(prev_size == variables.size()){
        errorManager::add(Error{std::string("Already Declared variable: " + name), nodePtr});
    }

}
void Method::addParameter(std::string name, Record *parameter, Node* nodePtr){    
    bool doesNotExist = true;
    for(auto p : parameters){
        if(p->name == name){
            doesNotExist = false;
            break;
        }
    }
    if(doesNotExist) {
        parameters.push_back(new Param{name, dynamic_cast<Variable*>(parameter)});
    }else{
        errorManager::add(Error{std::string("Already Declared parameter: " + name),nodePtr});
    }
     
}

Variable* Method::lookUpVariable(std::string key){

    //variables.find(key)->second;
    auto res = variables.find(key);

    if(res->first.empty()){
        return nullptr;
    }

    return res->second;
}

void Method::print(int spaces){
    
    print_spaces(spaces);
    printf("id: %s type:%s\t\n\t\t\tParams: \t", id.c_str(), type.c_str());
    bool first = true;
    if(parameters.size() > 0){printf("[\n");}
    for(auto param : parameters){
        if(first){
            print_spaces(spaces);     
            printf("\t\t\t");
            printf("id: %s type:%s", param->variable->id.c_str(), param->variable->type.c_str());   
        }else{
            printf(",\n");
            print_spaces(spaces);     
            printf("\t\t\t");
            printf("id: %s type:%s", param->variable->id.c_str(), param->variable->type.c_str());   
        }
        first= false;
        
    }
    if(parameters.size() > 0){
        print_spaces(spaces);     
        printf("\n\t\t\t\t\t");
        printf("]\n");   
    }else{         
        printf("[ ]\n");  
    }
         
    for(auto const & [s, r] : variables){
        
        r->print(spaces+1);
    }
    
}

