#pragma  once
#include <string>
#include <string_view>
//#include <type_traits>
#include <vector>
#include "Byteinfo.hh"

enum class TacType{
    Normal,
    Expression,
    Unary,
    Copy,
    ArrayAccess,
    ArrayCopy,
    New,
    New_Array,
    lenght,
    Parameter,
    MethodCall,
    PrintCall,
    theReturn,
    UnCondJump,
    CondJump
};



class Tac{
public:
    Tac();
    Tac(std::string LHS, std::string OP, std::string RHS, std::string RES);
    void print();
    virtual std::string to_String();
    virtual std::vector<byteInfo> getByteInfo();
    virtual ~Tac(){}
    std::string LHS, OP, RHS, RES;
    TacType id;
};

class  Expression : public Tac{
    public:
    Expression(std::string LHS, std::string OP, std::string RHS, std::string RES);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class Unary_expression : public Tac{
    public: 
    Unary_expression(std::string RES, std::string OP, std::string RHS);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class Copy : public Tac{
public:
    Copy(std::string RES, std::string LHS);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class ArrayAccess : public Tac{
    public: 
    ArrayAccess(std::string RES, std::string RHS, std::string index);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class ArrayCopy : public Tac{
    public: 
    ArrayCopy(std::string RES, std::string index, std::string RHS);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  New : public Tac{
    public: 
    New(std::string RES, std::string TYPE);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  New_Array: public Tac{
    public: 
    New_Array(std::string RES, std::string TYPE, std::string SIZE);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  lenght : public Tac{
    public: 
    lenght(std::string RES, std::string LHS);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  Parameter : public Tac{
    public: 
    Parameter(std::string param);//param y
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  MethodCall : public Tac{
public:
    std::string target;
    MethodCall(std::string RES, std::string FUNC, std::string NROFP);
    std::vector<byteInfo> getByteInfo() override;
    void set_target(std::string target);
    std::string to_String() override;
};

class  PrintCall : public Tac{
public:
    PrintCall();
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class theReturn : public Tac{
public: 
    theReturn(std::string tReturn);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class  UnCondJump : public Tac{
public:
    UnCondJump(std::string label);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

class CondJump : public Tac{
public:
    CondJump(std::string theBOOL, std::string label);
    std::vector<byteInfo> getByteInfo() override;
    std::string to_String() override;
};

