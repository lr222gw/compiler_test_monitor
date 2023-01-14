#include "Tacs.hh"
#include "Byteinfo.hh"
#include <string>
Tac::Tac(){
    LHS = "";
    OP = "";
    RHS = "";
    RES = "";
    id = TacType::Normal;
};
Tac::Tac(std::string LHS, std::string OP, std::string RHS, std::string RES){
    this->LHS = LHS;
    this->OP = OP;
    this->RHS = RHS;
    this->RES = RES;
    id = TacType::Normal;
};

void Tac::print(){
    printf("%s := %s %s %s\n", RES.c_str(), LHS.c_str(), OP.c_str(), RHS.c_str());
};

//MAKERS

Expression::Expression(std::string LHS, std::string OP, std::string RHS, std::string RES):
Tac(LHS, OP, RHS, RES)
{id = TacType::Expression;};

Unary_expression::Unary_expression(std::string RES, std::string OP, std::string RHS)
: Tac("", OP, RHS, RES)
{id = TacType::Unary;
}

Copy::Copy(std::string RES, std::string LHS):
Tac(LHS, "", "", RES)
{id = TacType::Copy;};

//ArrayAccess::ArrayAccess(std::string RES, std::string RHS):
ArrayAccess::ArrayAccess(std::string RES, std::string LHS, std::string index):
Tac(LHS,"", "["+index+"]", RES) //NOTE:  Brackets might be removed and only printed later?
{id = TacType::ArrayAccess;
}
ArrayCopy::ArrayCopy(std::string RES, std::string LHS, std::string index):
Tac(LHS,"", "["+index+"]", RES) //NOTE:  Brackets might be removed and only printed later?
{id = TacType::ArrayCopy;
}

New::New(std::string RES, std::string TYPE)
{
    this->RES = RES;
    this->OP = "new";
    this->LHS = TYPE;
    id = TacType::New;
};

New_Array::New_Array(std::string RES, std::string TYPE, std::string SIZE){
    this->RES = RES;
    this->LHS = TYPE;
    this->RHS = SIZE;
    id = TacType::New_Array;
};

lenght::lenght(std::string RES, std::string LHS):
Tac(LHS,"length","",RES){id = TacType::lenght;};

Parameter::Parameter(std::string param){
    this->RES = param;
    id = TacType::Parameter;
};

//MethodCall::MethodCall(std::string FUNC, std::string NROFP):
MethodCall::MethodCall(std::string RES, std::string FUNC, std::string NROFP):
Tac(FUNC,"call", NROFP, RES)
{id = TacType::MethodCall;};

PrintCall::PrintCall():
Tac("print","call", "2", "")    //NOTE: two parameters, first one is 'system' that doesnt 
{id = TacType::PrintCall;};     //      really exist and the second is the value... This is a 'cosmetic' change,
                                //      that doesnt matter since we treat print different from other function calls...

theReturn::theReturn(std::string tReturn):
Tac(tReturn,"call", "", "")
{
    RES = tReturn;
    this->OP = "return";
    id = TacType::theReturn;
};

UnCondJump::UnCondJump(std::string BB){
    this->RES = BB;
    this->OP = "goto";
    id = TacType::UnCondJump;
};

CondJump::CondJump(std::string theBOOL, std::string BB):
Tac(theBOOL, "goto", "", BB){id = TacType::CondJump;};

//TO STRING FUNCTIONS
std::string Tac::to_String(){
    return RES + ":= " + LHS + " " + OP + " " + RHS;
};
std::string Expression::to_String(){
    return Tac::to_String();
};
std::string Unary_expression::to_String(){
    return RES + " := " + OP + " " + RHS;
}
std::string Copy::to_String(){
    return RES + " := " + LHS;
}
std::string ArrayAccess::to_String(){//make this to copy contructor?
    return RES + " := " + LHS + RHS;
};
std::string ArrayCopy::to_String(){//make this to copy contructor?
    return RES + RHS + " := " + LHS;
};
std::string New::to_String(){
    return RES + " := " + OP + " " + LHS;
};
std::string New_Array::to_String(){
    return RES + " := new " + LHS + ", " + RHS;
};
std::string lenght::to_String(){
    return RES + " := "+OP+" " + LHS;
};
std::string Parameter::to_String(){
    return "param " + RES;
};
std::string MethodCall::to_String(){
    return RES + " := "+OP+" " + LHS + ", " + RHS;
};
std::string PrintCall::to_String(){
    return OP+" " + LHS + ", " + RHS;
};
std::string theReturn::to_String(){
    return OP +" " + RES;
};
std::string UnCondJump::to_String(){
    return "goto " + RES; 
};
std::string CondJump::to_String(){
    return "iffalse " + LHS +  " goto " + RES; 
};

void getbyteCodeFromOP(std::string OP, std::vector<byteInfo>& theRet){
    if(OP == "+"){
        theRet.push_back(byteInfo(ByteType::iAdd));
    }
    else if(OP == "-"){
        theRet.push_back(byteInfo(ByteType::iSub));
    }
    else if(OP == "*"){
        theRet.push_back(byteInfo(ByteType::iMul));
    }
    else if(OP == "/"){
        theRet.push_back(byteInfo(ByteType::iDiv));
    }
    else if(OP == "<"){
        theRet.push_back(byteInfo(ByteType::iLt));
    }
    else if(OP == "&&"){
        theRet.push_back(byteInfo(ByteType::iAnd));
    }
    else if(OP == "||"){
        theRet.push_back(byteInfo(ByteType::iOr));
    }
    else if(OP == "!"){
        theRet.push_back(byteInfo(ByteType::iNot));
    }
    else if(OP == "=="){
        theRet.push_back(byteInfo(ByteType::iSub));
        theRet.push_back(byteInfo(ByteType::iNot));
    }
}
ByteType getNumOrID(std::string &val){
    ByteType ret = ByteType::iLoad; 
    if(val[0] == '$'){
        ret = ByteType::iConst;
        val.erase(0,1);

        
    }
    
    return ret;
}
//to byte code
//TODO:  Uncomment this?
//std::vector<byteInfo> Tac::getByteInfo(){/*nothing doesn't exist*/};

std::vector<byteInfo> Tac::getByteInfo()
{
    return std::vector<byteInfo>(); //TODO: REMOVE THIS... FUNCTION...
};

std::vector<byteInfo> Expression::getByteInfo(){
    std::vector<byteInfo> ret;
    auto T = getNumOrID(this->LHS);
    ret.push_back(byteInfo(T, this->LHS));

    T = getNumOrID(this->RHS);
    ret.push_back(byteInfo(T, this->RHS));

    getbyteCodeFromOP(this->OP, ret);

    T = getNumOrID(this->RES);
    ret.push_back(byteInfo(ByteType::iStore, this->RES));
    return ret;    
};
std::vector<byteInfo> Unary_expression::getByteInfo(){
    std::vector<byteInfo> ret;
    auto T = getNumOrID(this->RHS);
    ret.push_back(byteInfo(T, this->RHS));
    ret.push_back(byteInfo(ByteType::iNot));
    ret.push_back(byteInfo(ByteType::iStore, this->RES));
    return ret;  
};
std::vector<byteInfo> Copy::getByteInfo(){
    std::vector<byteInfo> ret;
    auto T = getNumOrID(this->LHS);
    ret.push_back(byteInfo(T, this->LHS));
    ret.push_back(byteInfo(ByteType::iStore, this->RES));
    return ret;  
};
std::vector<byteInfo> ArrayAccess::getByteInfo(){
    std::vector<byteInfo> ret;
    //skip
    return ret;  
};
std::vector<byteInfo> ArrayCopy::getByteInfo(){
    //skip?
    std::vector<byteInfo> ret;
    return ret;
};
std::vector<byteInfo> New::getByteInfo(){
    std::vector<byteInfo> ret;
    //skip for the moment 
    //ret.push_back(byteInfo(ByteType::iConst, this->LHS));
    //ret.push_back(byteInfo(ByteType::iStore, this->RES));
    return ret;  
};
std::vector<byteInfo> New_Array::getByteInfo(){
    //skip?
    std::vector<byteInfo> ret;
    return ret;
};
std::vector<byteInfo> lenght::getByteInfo(){
    std::vector<byteInfo> ret;
    //skip
    return ret;
};
std::vector<byteInfo> Parameter::getByteInfo(){
    std::vector<byteInfo> ret;    
    auto T = getNumOrID(this->RES);
    ret.push_back(byteInfo(T, this->RES));
    return ret;
};
std::vector<byteInfo> MethodCall::getByteInfo(){
    std::vector<byteInfo> ret;
    ret.push_back(byteInfo(ByteType::invokevirtual,target+"."+LHS));
    ret.push_back(byteInfo(ByteType::iStore,RES));
    return ret;
}

void MethodCall::set_target(std::string target)
{
    this->target = target;   
};
std::vector<byteInfo> PrintCall::getByteInfo(){
    std::vector<byteInfo> ret;    
    ret.push_back(byteInfo(ByteType::iPrint));
    return ret;
};
std::vector<byteInfo> theReturn::getByteInfo(){
    std::vector<byteInfo> ret;
    auto T = getNumOrID(this->LHS);
    ret.push_back(byteInfo(T, this->LHS));
    ret.push_back(byteInfo(ByteType::iReturn));
    return ret;  
};

//TODO:  Uncomment this?
std::vector<byteInfo> UnCondJump::getByteInfo(){
    std::vector<byteInfo> ret;
    ret.push_back(byteInfo(ByteType::igoto, this->RES));
    return ret;
};
std::vector<byteInfo> CondJump::getByteInfo(){
    //something more
    std::vector<byteInfo> ret;
    auto T = getNumOrID(this->LHS);
    ret.push_back(byteInfo(T, this->LHS));
    ret.push_back(byteInfo(ByteType::iffalse_goto, this->RES));
    return ret;
};

