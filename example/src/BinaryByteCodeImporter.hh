#pragma once
#include<fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <sys/types.h>
#include "ByteCodeStructures.hh"

class BinaryByteCodeImporter{
public:
    BinaryByteCodeImporter( std::string  pathToByteCode);
    Program_byteCode* readFile();
    Program_byteCode* the_program;
private:
    std::string byteCodePath;
};