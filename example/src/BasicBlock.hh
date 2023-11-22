#pragma once
#include <string>
#include "Tacs.hh"
#include <vector>
#include "Node.h" //TEMP: for testing

class BasicBlock{
public:
    BasicBlock();
//private:
    Node* node; //TEMP:For testing
    std::string name; 
    std::vector<Tac*> tacInstructions;
    Tac condition;

    BasicBlock* trueExit;
    BasicBlock* falseExit;
    
};