#pragma once

#include "Node.h"
#include <vector>
#include <map>
#include "errorMandager.hh"
#include "Record.hh"
#include "Variable.hh"
#include "Method.hh"
#include "Class.hh"
#include "Program.hh"

class Scope{
public:
    Scope(Scope* parent);
    virtual ~Scope();
    int next = 0;
    Scope* parentScope;
    std::vector<Scope*> childrenScopes;
    std::map<std::string, Record*> records;

    Scope* nextChild();
    Record* lookUp(std::string key);
    void resetScope();
    void put(std::string key, Record* record);
};



class SymbolTable{
public:
    
    SymbolTable(Node* root_node);
    virtual ~SymbolTable();

    Node* traverseAST(Node* current, int depth = 0);

    void enterScope();
    void exitScope();

    void put(std::string key, Record *item);
    Record* lookUp(std::string key);

    Method* getMethod(std::string &className, const std::string &methodName);

    void print();
    void resetTable();

private: //TODO:  fix... getters... (??)
    Scope* root;
    Scope* current;
    Node* AST_root;
    
    Program* program;
    Class* currentClass;
    Method* currentMethod;
    Variable* currentVariable;
};



//#endif



















