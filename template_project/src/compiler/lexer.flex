%{
    #include "LocThing.hh"
    #include "Node.h"
    #include "parser.tab.hh"        
    #include "defs.hh"

%}
%option noyywrap nounput batch noinput stack yylineno
NUMBERS     0|[1-9][0-9]*

%{
    // Code run each time a pattern is matched. (Stolen from bison example files)
    # define YY_USER_ACTION  loc.columns (yyleng);      
%}

%%

%{   
    //Runs when yylex() runs
    yy::location& loc = locThing.location;

    // Below are 5 examples of how symbols can be definied
    // The first two are most common. newline/tab/eof are the different
%}


"else"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_ELSE(yytext, loc);           	}
{NUMBERS}             {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_NUMBERS(yytext, loc);        	}
[ \t]+                {loc.step();}
\n                    {loc.lines(yyleng);loc.step();}

<<EOF>>                return yy::parser::make_END(loc);


%%
/* END OF FILE*/