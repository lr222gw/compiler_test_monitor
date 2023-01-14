#include "BinaryByteCodeExporter.hh"


BinaryByteCodeExporter::BinaryByteCodeExporter(Program_byteCode& programByteCode){
    writeFile(programByteCode);
}

void BinaryByteCodeExporter::writeFile(Program_byteCode& programByteCode){
    

    std::ofstream wf("byte.dat", std::ios::out | std::ios::binary);
    if (!wf) {
        std::cout << "cannot open" << std::endl;
        assert(false && "byte.dat could not be open or created.");
    }
    else {

        //Program_byteCode To binary ...
        //Store number of Methods of Program_byteCode
        std::int64_t nrOfMethods_vec = static_cast<std::int64_t>(programByteCode.methods.size());
        wf.write((char*)&nrOfMethods_vec, sizeof(nrOfMethods_vec));

        for(int i = 0; i < nrOfMethods_vec; i++ ){
            Method_byteCode* currentMethod = &programByteCode.methods[i];

            //Store length of Method Label, then store label 
            int64_t methodLabel_length = static_cast<std::int64_t>(currentMethod->label.length() + 1 );  // add 1 for \0
            wf.write((char*)&methodLabel_length, sizeof(methodLabel_length));

            std::string methodLabel = currentMethod->label;
            wf.write(methodLabel.c_str(), methodLabel_length * static_cast<std::int64_t>(sizeof(char)));

            //Store Number of Variables in current Method
            std::int64_t nrOfVariables = static_cast<std::int64_t>(currentMethod->variables.size());
            wf.write((char*)&nrOfVariables, sizeof(nrOfVariables));

            for(int j = 0; j < nrOfVariables; j++ ) {
                Variable* currentVariable = &currentMethod->variables[j];

                //Store length of Variabel ID string, then store ID string 
                int64_t variable_ID_length = static_cast<std::int64_t>(currentVariable->id.length() + 1 );  // add 1 for \0
                wf.write((char*)&variable_ID_length, sizeof(variable_ID_length));

                std::string variable_ID = currentVariable->id;
                wf.write(variable_ID.c_str(), variable_ID_length * static_cast<std::int64_t>(sizeof(char)));

                //Store length of Variabel TYPE string, then store TYPE string
                int64_t variable_TYPE_length = static_cast<std::int64_t>(currentVariable->type.length() + 1 );  // add 1 for \0
                wf.write((char*)&variable_TYPE_length, sizeof(variable_TYPE_length));

                std::string variable_TYPE = currentVariable->type;
                wf.write(variable_TYPE.c_str(), variable_TYPE_length * static_cast<std::int64_t>(sizeof(char)));
            }

            //Store Number Of Method Blocks in current Method
            std::int64_t nrOfMethodBlocks = static_cast<std::int64_t>(currentMethod->method_blocks.size());
            wf.write((char*)&nrOfMethodBlocks, sizeof(nrOfMethodBlocks));

            for(int j = 0; j < nrOfMethodBlocks; j++ ) {
                Block_byteCode* currentMethodBlock = &currentMethod->method_blocks[j];

                //Store length of Method Block Label string, then store Method Block Label string 
                int64_t MethodBlock_label_length = static_cast<std::int64_t>(currentMethodBlock->label.length() + 1); // add 1 for \0
                wf.write((char*)&MethodBlock_label_length, sizeof(MethodBlock_label_length));

                std::string MethodBlock_label = currentMethodBlock->label;
                wf.write(MethodBlock_label.c_str(), MethodBlock_label_length * static_cast<std::int64_t>(sizeof(char)));

                //Store Number Of byteInfo instructions, then store the vector with data
                std::int64_t nrOfByteInfos = static_cast<std::int64_t>(currentMethodBlock->instructions.size());
                wf.write((char*)&nrOfByteInfos, sizeof(nrOfByteInfos));
                
                for(int k = 0; k < nrOfByteInfos; k++){
                    byteInfo* currentInstruction = &currentMethodBlock->instructions[k];

                    //Store length of byteinfo object string, then store byteinfo object string
                    int64_t byteInfo_objectStr_length = static_cast<std::int64_t>(currentInstruction->object.length() + 1); // add 1 for \0
                    wf.write((char*)&byteInfo_objectStr_length, sizeof(byteInfo_objectStr_length));

                    std::string byteInfo_objectStr = currentInstruction->object;
                    wf.write(byteInfo_objectStr.c_str(), byteInfo_objectStr_length * static_cast<std::int64_t>(sizeof(char)));

                    //Store the ByteType 
                    std::int64_t byteType = static_cast<std::int64_t>(currentInstruction->type);
                    wf.write((char*)&byteType, sizeof(byteType));
                    
                }                
            }
        }
        
        wf.close();
        if (!wf.good()) {
            std::cout << "error" << std::endl;
            assert(wf.good() && "byte.dat could not be closed.");
        }
    }

}