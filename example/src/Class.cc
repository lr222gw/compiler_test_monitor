#include "Class.hh"
#include <cstddef>
#include <string>
#include <utility>

Class::~Class()
{
    
    for (auto itr = memberVariables.begin(); itr != memberVariables.end(); itr++  ) {
        delete itr->second;
    }
    for (auto itr = memberMethods.begin(); itr != memberMethods.end(); itr++  ) {
        delete itr->second;
    }
    
}

Class::Class(std::string name, std::string type)
    : Record(name, type)
{    
}

void Class::addVariable(std::string name, Record *variable , Node* nodePtr){
    int prev_size = memberVariables.size(); 
    memberVariables.insert(std::make_pair(name, dynamic_cast<Variable*>(variable)));
    if(prev_size == memberVariables.size()){
        errorManager::add(Error{std::string("Already Declared variable: " + name), nodePtr});
    }
}
void Class::addMethod(std::string name, Record *method, Node* nodePtr){

    Method* eh  =dynamic_cast<Method*>(method);
    int prev_size = memberMethods.size(); 
    memberMethods.insert(std::make_pair(name, eh));
    if(prev_size == memberMethods.size()){
        errorManager::add(Error{std::string("Already Declared Function: " + name), nodePtr});
    }
}
Method *Class::lookUpMethod(std::string key){
    std::map<std::string, Method*>::iterator pair = memberMethods.find(key);
    if(memberMethods.count(key) == 0){
        return nullptr;
    }
    
    if(pair == memberMethods.end()){ 
        return nullptr;
    }

    return pair->second;
}
Variable *Class::lookUpVariable(std::string key){
    return memberVariables.find(key)->second;
    
}

void Class::print(int spaces){
    print_spaces(spaces);
    printf("id: %s type:%s\n", id.c_str(), type.c_str());
    for(auto const & [s, r] : memberVariables){
        
        r->print(spaces+1);
    }

    for(auto const & [s, r] : memberMethods){
        
        r->print(spaces +1);
    }
    
}