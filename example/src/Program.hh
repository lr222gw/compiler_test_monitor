#pragma once
#include <map>
#include "Record.hh"
#include "Class.hh"

class Program : public Record{
    public:
    Program();
    std::map<std::string, Class*> programClasses;
    void addClass(std::string name, Record* _class, Node* nodePtr);
    Class* lookUpClass(std::string key);

    ~Program();
};
