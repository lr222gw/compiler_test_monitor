#include "Program.hh"

Program::Program()
    : Record("Program", "Program")
    {}

Program::~Program()
{
    
    for (auto itr = programClasses.begin(); itr != programClasses.end(); itr++  ) {
        delete itr->second;
    }
    
}

void Program::addClass(std::string name, Record* _class, Node* nodePtr){
    int prev_size = programClasses.size(); 
    programClasses.insert(std::make_pair(name, dynamic_cast<Class*>(_class)));
    if(prev_size == programClasses.size()){
        errorManager::add(Error{std::string("Already Declared Class: " + name), nodePtr});
    }
}
Class* Program::lookUpClass(std::string key){
    return programClasses.find(key)->second;
}