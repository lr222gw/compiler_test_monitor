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


class BinaryByteCodeExporter{
public:
    BinaryByteCodeExporter(Program_byteCode& programByteCode);
private:
    void writeFile(Program_byteCode& programByteCode);
    
};