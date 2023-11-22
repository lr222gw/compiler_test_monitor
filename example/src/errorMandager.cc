#include "errorMandager.hh"
#include "Node.h"

errorManager* errorManager::get_instance() 
{
     static errorManager* _theInstance;
    if (_theInstance == nullptr) { _theInstance = new errorManager(); }
    return _theInstance;
}

void errorManager::add(Error err) 
{
    get_instance()->errorList.push_back(err);
}

bool errorManager::hasError() 
{
    return !get_instance()->errorList.empty();
}


void errorManager::presentErrors() 
{

    std::cout << "StartOfErrors:\n";
    for (auto e : get_instance()->errorList) {
        if(e.node) {
            
            if(RULE_COMPILER_LINE_ERROR_MESSAGE && !e.compilerLine.empty()){
                printf("{%4d}::Error[%4d]: %s\n",std::atoi(e.compilerLine.c_str()), e.node->line.start_line, e.error.c_str());
            }else{
                printf("Error[%4d]: %s\n", e.node->line.start_line, e.error.c_str());
            }            
        }else {
            if(RULE_COMPILER_LINE_ERROR_MESSAGE && !e.compilerLine.empty()){
                printf("{%4d}::Error: %s\n",std::atoi(e.compilerLine.c_str()), e.error.c_str());
            }else{
                printf("Error: %s\n", e.error.c_str());
            }            
        }
    }
    std::cout << "EndOfErrors\n"; 
}
