%{
    #include "LocThing.hh"
    #include "Node.h"
    #include "parser.tab.hh"        
    #include "defs.hh"

%}
%option noyywrap nounput batch noinput stack yylineno
NUMBERS     0|[1-9][0-9]*
ALPHAB      [a-zA-Z]+
IDENTIFIER  [a-zA-Z_][a-zA-Z0-9_]*


%{
    // Code run each time a pattern is matched. (Stolen from bison example files)
    # define YY_USER_ACTION  loc.columns (yyleng);      
%}

%%

%{   
    //Runs when yylex() runs
    yy::location& loc = locThing.location;
%}


"else"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_ELSE(yytext, loc);           		}
"!"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_EXCLAIMATION(yytext, loc);   	}
"new"                 {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_NEW(yytext, loc);            	}
"false"               {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_FALSE(yytext, loc);          		}
"true"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_TRUE(yytext, loc);           		}
"this"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_THIS(yytext, loc);           		}
"length"              {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_LENGTH(yytext, loc);         		}
"//".*              
"/"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_DIV(yytext, loc);            	}
"=="                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_EQUEQU(yytext, loc);         	}
">"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_MORE_T(yytext, loc);         	}
"<"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_LESS_T(yytext, loc);         	}
"||"                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_OR(yytext, loc);             	}
"&&"                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_AND(yytext, loc);            	}
"="                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_EQU(yytext, loc);            	}
"System.out.println"  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("O_PRINT:Flex LINE[%4d]\n", yylineno); }       return yy::parser::make_SYSTEM_O_PRINT(yytext, loc); 				}
"while"               {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_WHILE(yytext, loc);          		}
"if"                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_IF(yytext, loc);             	}
"boolean"             {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_BOOLEAN(yytext, loc);        		}
"int"                 {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_TYPE_INT(yytext, loc);            		}
";"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_SEMICOLON(yytext, loc);      	}
","                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_COMMA(yytext, loc);          	}
"return"              {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_RETURN(yytext, loc);         		}
"extends"             {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_EXTENDS(yytext, loc);        		}
"]"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_C_B(yytext, loc);            	}
"["                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_O_B(yytext, loc);            	}
"String"              {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_STRING(yytext, loc);         	}
"main"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_MAIN(yytext, loc);           	}
"void"                {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_VOID(yytext, loc);           	}
"static"              {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}	   	return yy::parser::make_STATIC(yytext, loc);         	}
"public"              {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_PUBLIC(yytext, loc);         	}
"}"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_C_M(yytext, loc);            	}
"{"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_O_M(yytext, loc);            	}
"class"               {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_CLASS(yytext, loc);          	}
"++"                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_ADDADD(yytext, loc);         	}
"--"                  {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_SUBSUB(yytext, loc);         	}

"+"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_ADD(yytext, loc);            	}
"-"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_SUB(yytext, loc);            	}
"*"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_MULT(yytext, loc);           	}
"("                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_O_P(yytext, loc);            	}
")"                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_C_P(yytext, loc);            	}
"."                   {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_DOT(yytext, loc);            	}

{IDENTIFIER}          {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_IDENTIFIER(yytext, loc);     	}
{NUMBERS}             {if(RULE_IGNORE_SEMANTIC_DEBUG_PRINT){printf("%s:Flex LINE[%4d]\n", yytext,yylineno);}		return yy::parser::make_NUMBERS(yytext, loc);        	}
[ \t]+                {loc.step();}
\n                    {loc.lines(yyleng);loc.step();}

<<EOF>>                 return yy::parser::make_END(loc);


%%
/* END OF FILE*/