#include "LocThing.hh"
#include "parser.tab.hh"



LocThing::LocThing() 
{}
        
int LocThing::parse(){
    
    yy::parser parse(*this);    
    int res = parse();    
    return res;
}
        
