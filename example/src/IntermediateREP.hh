#pragma once
#include "Node.h"
#include <vector>
#include "BasicBlock.hh"
#include "SymbolTable.hh"



struct CFG{
    std::string fName = "fName.1";
    //a block with links
    BasicBlock* rootBlock;
    Node* AST_subroot;
    std::string getClass = "";
};

struct NodeBlock {
    std::string TAC_address_name;
    Node* node = nullptr;
    BasicBlock* block = nullptr;     
};

class IntermediateRepresentation{
public:
    IntermediateRepresentation(Node *AST, SymbolTable *ST);
    void printme();
    void generate_CFG();

    std::vector<CFG*>* getCFGs();

private: //TEMP: just to get access
    //need to store CFGs
    std::vector<CFG*> CFGs;    

    NodeBlock* ret;
    SymbolTable* symbolTable;
    Method* currentMethod;

    void printme_rec(BasicBlock* ptr, int spaces);
    void generate_CFG_content(BasicBlock &basicBlock, int count, ofstream *outStream); 

    int nameId;
    std::string genName();
    
    NodeBlock* traverseAST(Node* node, BasicBlock* _currentBlock);//Building CFGs content
    void AST_to_CFG_roots(Node* node, std::string currentclass);//Building CFGs ROOTS

    
};