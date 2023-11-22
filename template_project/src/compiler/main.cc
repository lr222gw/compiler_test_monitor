
#include "parser.tab.hh"
#include "LocThing.hh"
#include "errorManager.hh"
#include <cstdio>
#include <fstream>
#include <iostream>

#include <cassert>
#include <cstring>
extern Node *root;
extern FILE *yyin;
enum errCodes
{
    SUCCESS         = 0,
    FAILED_GRAMMAR  = 1,
    FAILED_TREE     = 2,
    FAILED_SEMANTIC = 3,
    SEGMENT_FAULT   = 139 
};

int errCode = errCodes::SUCCESS;
void yy::parser::error(const location_type &loc, const string &err)
{
    std::cout << "\nLAST_LINE[" << loc << "]" << std::endl;
    std::cout << "Cannot generate a syntax tree for this input: " << err
              << std::endl;
    errCode = errCodes::FAILED_GRAMMAR;
}

int extracted(int &argc, char **&argv)
{    
    LocThing parser;

    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            errCode = errCodes::FAILED_GRAMMAR;
        }
    }

    // Begin parsing
    if (!parser.parse())
    {
        // Print Tree

        // Generate Tree .dot-file
        
        // Preform Semantic Analyse

        if(errorManager::hasError())
        {
            errCode = FAILED_SEMANTIC;
            errorManager::presentErrors();
        }
        else
        {
            // Create Intermediate Representation

            // Generate CFG .dot-file        
            
            //NOTE: if user sends '-b', compiler will generate byte code, otherwise not...
            if(argc == 3 && std::strcmp(argv[2], "-b") == 0){
                
                // Export as ByteCode

            }else{
                 std::cout << "OBS: Compiler does not generate bytecode! \nSend '-b' as argument to generat bytecode." << std::endl; 
            }            
        }     
    }
    else
    {
        errCode = errCode == errCodes::SUCCESS ? errCodes::FAILED_TREE : errCode;
    }

    fclose(yyin);
    delete root;
    return errCode;
}
int main(int argc, char **argv)
{
    // Reads from file if a file name is passed as an argument. Otherwise, reads
    // from stdin.
    return extracted(argc, argv);
}

