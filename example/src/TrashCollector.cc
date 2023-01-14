#include "TrashCollector.hh"
#include "BasicBlock.hh"
#include "SymbolTable.hh"
    
Record* TrashCollector::CreateRecord(std::string name ,std::string type){

    Record* returnRec = get_instance()->findRecord(name, type);

    if(returnRec == nullptr){
        returnRec =  new Record(name, type);;
        get_instance()->RecList.push_back(returnRec);
    }
    return returnRec;
    
}

Node* TrashCollector::CreateNode(string t, string v, lineStruct line){
    Node* returnNode = get_instance()->findNode(t, v, line);

    if(returnNode == nullptr){
        returnNode = new Node(t, v, line);
        get_instance()->nodeList.push_back(returnNode);
    }
    return returnNode;
}
BasicBlock* TrashCollector::CreateBlock(std::string name){
    BasicBlock* temp = new BasicBlock();
    temp->name = name;
    get_instance()->BasicBlocks.push_back(temp);
    return temp;
}

TrashCollector* TrashCollector::get_instance()
{
    static TrashCollector* _theInstance;
    if (_theInstance == nullptr) { _theInstance = new TrashCollector(); }
    return _theInstance;
}

Record* TrashCollector::findRecord(std::string name, std::string type){
    Record* found = nullptr;
    for(int i = 0; i < RecList.size() && found == nullptr; i++){
        if(RecList[i]->id == name && RecList[i]->type == type){
            found = RecList[i];
        }
    }
    return found;
}
Node* TrashCollector::findNode(std::string t, std::string v, lineStruct line){
    Node* found = nullptr;
    for(int i = 0; i < nodeList.size() && !found; i++){
        if(nodeList[i]->value == v && nodeList[i]->type == t && nodeList[i]->line.start_line == line.start_line){
            found = nodeList[i];
        }
    }
    return found;
}
TrashCollector::TrashCollector()
{

}

TrashCollector::~TrashCollector()
{
    for(auto r : RecList){
        delete r;
    }
    for(auto n : nodeList){
        delete n;
    }
    for(int i = 0; i < BasicBlocks.size(); i++){
        delete BasicBlocks[i];
    }
}
