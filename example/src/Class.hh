#pragma once
#include "Record.hh"
#include "Variable.hh"
#include "Method.hh"
#include "errorMandager.hh"
#include <map>

class Class : public Record {
public:
    Class(std::string name, std::string type);
    std::map<std::string, Variable*> memberVariables;
    std::map<std::string, Method*> memberMethods;

    void addVariable(std::string name, Record *variable, Node* nodePtr);
    void addMethod(std::string name, Record *method, Node* nodePtr);
    Variable* lookUpVariable(std::string key);
    Method* lookUpMethod(std::string key);

    void print(int spaces) override;

    ~Class();

};