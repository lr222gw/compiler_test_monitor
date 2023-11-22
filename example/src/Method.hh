#pragma once
#include <string>
#include <map>
#include <vector>
#include "errorMandager.hh"
#include "Node.h"
#include "Variable.hh"

struct Param{
    std::string name;
    Variable* variable;
    ~Param();
};

class Method : public Record {
public:
    Method(std::string name, std::string returnType);
    std::vector<Param*> parameters;
    std::map<std::string, Variable*> variables;
    virtual ~Method();

    void addVariable(std::string name, Record *variable, Node* nodePtr);
    void addParameter(std::string name, Record *param, Node* nodePtr);
    Variable* lookUpVariable(std::string key);

    void print(int spaces) override;
};