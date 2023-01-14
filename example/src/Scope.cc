#include "SymbolTable.hh"


Scope::Scope(Scope *parent){
    this->parentScope = parent;
}

Scope::~Scope(){
    for(int i = 0; i < childrenScopes.size(); i++){
        delete childrenScopes[i];
    }
}

Scope* Scope::nextChild(){
    Scope* nextChild;
    if(next == childrenScopes.size()){
        nextChild = new Scope(this);
        childrenScopes.push_back(nextChild);
    }else{
        nextChild = childrenScopes.at(next);
    }
    next++;
    return nextChild;
}

Record* Scope::lookUp(std::string key){
    std::map<std::string, Record*>::iterator a;
    a = records.find(key);
    if(a == records.end()){
        if(parentScope == nullptr){
            return nullptr;
        }else{
            return parentScope->lookUp(key);;
        }
    }
    return a->second;
}

void Scope::resetScope(){
    next = 0;
    for(int i = 0; i < childrenScopes.size();i++){
        childrenScopes.at(i)->resetScope();
    }
}

void Scope::put(std::string key, Record* record){
    records.insert(std::make_pair(key, record));
}





