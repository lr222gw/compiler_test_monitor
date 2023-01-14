#pragma once
//#include "Tacs.hh"
#include <map>
//#include <system_error>
#include <vector>
//#include "SymbolTable.hh"
//#include "IntermediateREP.hh"
#include "Variable.hh"
#include "Byteinfo.hh"


class Block_byteCode{
public:
    Block_byteCode();
    std::string label; 
    std::vector<byteInfo> instructions;
};

class Method_byteCode{
public:
    Method_byteCode();
    std::string label;
    std::vector<Variable> variables;
    std::vector<Block_byteCode> method_blocks;
};


class Program_byteCode{
public:
    Program_byteCode();
    std::vector<Method_byteCode> methods;    
    std::map<std::string, Method_byteCode*> methods_map;    

};