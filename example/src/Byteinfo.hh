#pragma once
#include <string>


enum class ByteType{
    iLoad,
    iConst,
    iStore,
    iAdd,
    iSub,
    iMul,
    iDiv,
    iLt,
    iAnd,
    iOr,
    iNot,
    igoto,
    iffalse_goto,
    invokevirtual,
    iReturn,
    iPrint,
    iStop,
    Error = -1
};

const std::string ByteTypeToString[] = {
    "iLoad",
    "iConst",
    "iStore",
    "iAdd",
    "iSub",
    "iMul",
    "iDiv",
    "iLt",
    "iAnd",
    "iOr",
    "iNot",
    "igoto",
    "iffalse_goto",
    "invokevirtual",
    "iReturn",
    "iPrint",
    "iStop",    
    "Error"
};

struct byteInfo{
    ByteType type;
    std::string object;
    byteInfo() = default;
    byteInfo(ByteType type, std::string object = "");
    std::string to_string();
    int objectToInt();
};