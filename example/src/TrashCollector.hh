#pragma once
#include "SymbolTable.hh"
#include "defs.hh"
#include <vector>
#include "BasicBlock.hh"

class TrashCollector{
public:    
    virtual ~TrashCollector();
    void deleteall();
    static Record* CreateRecord(std::string name ,std::string type);
    static Node* CreateNode(std::string t, std::string v, lineStruct line);
    static BasicBlock* CreateBlock(std::string name);

    static TrashCollector* get_instance();    

private:
    TrashCollector();
    
    std::vector<Record*> RecList;
    std::vector<Node*> nodeList;
    std::vector<BasicBlock*> BasicBlocks;
    Record* findRecord(std::string name, std::string type);
    Node* findNode(std::string t, std::string v, lineStruct line);
};