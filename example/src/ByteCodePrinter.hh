#pragma once
#include <string>
#include <iostream>
#include "ByteCodeStructures.hh"

class ByteCodePrinter{
    private:
    ByteCodePrinter() = default;
    public:
    static void print(Program_byteCode& program);
};