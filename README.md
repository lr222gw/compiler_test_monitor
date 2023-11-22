# compiler_test_monitor

*Please use branch "base_project", it is the most updated*

**First draft of readme, feel free to ask for improvements. This was rushed together...**

## overview
A bash script made to make testing your own compiler easier.
Initially made for mini java byte code compiler, with support for testing an interpreter aswell.

On the initial run the script will setup the required folder structure.
All test files (i.e. code samples) should be placed in one of the subdirectory to the test directory. 

Running the script all other times will test your compiler on all the testfiles in the testfiles directory.
You will see a interactive cli with the results from the different tests.
All output from the tests can be investigated by providing the id for the test. 
If the compiler creates a dot file for the tree and cfg then these will be generated with dot to create a graphical representatiom, these will be placed in the corresponding directories
.

### Different kinds of tests
- Valid test: should contain source code exptected to succeed
- invalid grammar: should contain source code with invalid grammar
- invalid semantic: should contain source code with invalid semantics

## Requirements 
- Linux ( not tested on any other platforms)
- Bash (only tested in Manjaro and Ubunutu)
- Java, to run interpreter ( script will tell you if its missing)

Besides this the script also require a makefile to exist, it should have a rule for compiler and interpreter (even if the interpreter isn't needed).
This could be changed but hardcoded for my convenience.

All test can only exist of one file... Sadly

## Instructions 
Lazy instructions for the example and/or template:
1. Download repo
2. Cd into the example folder
3. Run script: `../run_tests.sh`. Wait for the folder structure to be created.
4. Add mini java test files to the subfolders of test within the newly constructed compiler_test_monitor_files folder.
5. Run the script again.


The script will handle compilation.
There's a silly dependency to the makefile:
There needs to be two rules named compiler and interpreter.

See the Template project to get a better idea of what is required...

## Regarding the Example
### Compiler errors on sample tests
When running the example you will see that the file TreeVisitor fails. 
This is expected since the example compiler lacks that functionality. 

### Interpreter errors on sample tests
Alot of the test files will cause errors for the interpreter implementation. 
This is to be expected since the example interpreter lacks the required finctionality.

## Good to know
Run the script with the -h flag to get more information.
Run the script with the -hh flag for verbose info.
