#pragma once
#include "Record.hh"

class Variable : public Record {
    public:
    Variable() = default;
    Variable(std::string name, std::string type);
    virtual ~Variable(){};
};