#pragma once
#include <string>

class Record{
public:
    Record() =default;
    Record(std::string name, std::string type);
    std::string id;
    std::string type;
    virtual void print(int spaces);
    void print_spaces(int spaces);
    virtual ~Record(){};
};