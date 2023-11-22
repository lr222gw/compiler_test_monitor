#include "Record.hh"

Record::Record(std::string name, std::string type)
    : id(name), type(type)
{
}

void Record::print(int spaces){
    print_spaces(spaces);
    printf("id: %s type:%s\n", id.c_str(), type.c_str());
}


void Record::print_spaces(int spaces){
    for(int i = 0; i < spaces; i++){
        printf("\t");
    }
}

