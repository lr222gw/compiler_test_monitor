#include "ByteCodePrinter.hh"


void ByteCodePrinter::print(Program_byteCode& program)
{
    static  ByteCodePrinter thePrinter = ByteCodePrinter();
    std::cout << "\n=============================" << std::endl;
    std::cout << "       Bytecode print" << std::endl;
    std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;

    for (auto method : program.methods) {
        std::cout << std::endl << method.label << std::endl;
        for(int i = 0; i < method.variables.size(); i++){
            std::cout << method.variables[i].id << std::endl;
        }
        for (auto method_block : method.method_blocks ) {            
            if(!method_block.label.empty()){std::cout << "\t" << method_block.label << std::endl;}
            for (auto instruction : method_block.instructions ) {                
                std::cout << "\t\t" << instruction.to_string() << std::endl;
            }
        }
    }
}
