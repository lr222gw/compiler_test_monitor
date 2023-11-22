#pragma once
#include <cassert>
#include "ByteCodeStructures.hh"
#include "SymbolTable.hh"
#include "IntermediateREP.hh"
#include "Tacs.hh"
#include "ByteCodePrinter.hh"
#include "errorMandager.hh"

struct ClassMethod_data{
    std::string Class;
    std::string Method;
};

class ByteCodeGenerator{    
public:
    ByteCodeGenerator(std::vector<CFG*>* CFGs, SymbolTable* symbolTable );
    
    void print();
    Program_byteCode& getProgramByteCode();
private:
    void generate_bytecode();
    void subCFG_to_bytecode(BasicBlock &basicBlock,Method_byteCode& methodName, ClassMethod_data dat);
    SymbolTable* symbolTable;
    std::vector<CFG*>* CFGs;

    Program_byteCode program;
};