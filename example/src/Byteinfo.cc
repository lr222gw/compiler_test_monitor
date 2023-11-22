#include "Byteinfo.hh"

byteInfo::byteInfo(ByteType type, std::string object ){
    this->type = type;
    this->object = object;
};


std::string byteInfo::to_string(){    
    
    return ByteTypeToString[(int)type] + " " + object;
}

int byteInfo::objectToInt(){
    int val; 
    if(object == "true"){        
        val = 1;
    }
    else if(object == "false"){
        val = 0;            
    }else{
        val = std::stoi(object);
    }
    return val;
}