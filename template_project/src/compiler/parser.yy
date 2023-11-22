%skeleton "lalr1.cc" 

%defines
//Assignemnt 2 test
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor
%code requires{
    #include <string>
    #include "Node.h"  
    #include "LineStruct.hh"
    
    class LocThing;    

}

%param { LocThing& locThing }

%locations

%code{
    
    #include "LocThing.hh"
    #include "defs.hh"
    Node* root;

    lineStruct to_linestruct(yy::location loc) {
    return lineStruct {
        loc.begin.line,
        loc.begin.column,
        loc.end.line,
        loc.end.column
    };  
}

}


%token <std::string> IDENTIFIER  NUMBERS ELSE

%token END 0 "end of file"

// definition of the production rules. All production rules are of type Node
%type <Node *> Identifier

%%
Identifier: IDENTIFIER 
{ 
    if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){std::cout << "idenfidier:" << $1 << " LINE["<< locThing.location << "]"  << std::endl;}
    $$ = new Node(TYPE_IDENTIFIER, $1 + "_", to_linestruct(@$));
}//id
%%
