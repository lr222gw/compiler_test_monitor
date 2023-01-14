#ifndef LOCTHING_HH
#define LOCTHING_HH
#include "parser.tab.hh"
#include <string>

#define YY_DECL yy::parser::symbol_type yylex(LocThing &locThing)
YY_DECL;

class LocThing {
public:
    
     LocThing();
    int result;    
    int parse();

    yy::location location;
};


#endif //! LOCTHING_HH
