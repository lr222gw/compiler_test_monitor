#pragma once

#include <string>
#include <vector>
#include "defs.hh"

class Node;
struct Error {
    std::string error; 
    Node* node;
    std::string compilerLine;
};

class errorManager {
private:
    errorManager() = default;
public:
    std::vector<Error> errorList;
    static errorManager* get_instance();
    static void add(Error err);    
    static bool hasError();
    static void presentErrors();
};
