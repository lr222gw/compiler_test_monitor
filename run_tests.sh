#!/bin/bash


#Defining colors for output...
RED='\033[0;31m'
LIGHT_RED='\u001b[31;1m'
GREEN='\033[0;32m'
DARKGREEN='\u001b[38;5;34m'
YELLOW='\u001b[33m'
CYAN='\u001b[36;1m'
FADEDCYAN='\u001b[38;5;72m'
DARK_LIGHT_BLUE='\u001b[38;5;39m'
LIGHT_BLUE='\u001b[38;5;87m'
NO_COL='\033[0m'

#Declaring some of the global variables 
compiler="compiler"
runningTestCases="ALL"

flag_compile="true"
flag_specificTest="false"
flag_specificCompiler="false"
flag_skipClean="true"
flag_noMenu="false"
flag_fast="false"
flag_onlyTrees="false"
flag_fullPath="false"
flag_onlyErrors="false"
flag_skipSemantic="false"
flag_help="false"
flag_ExtraHelp="false"
flag_RunInterpreter="false"
flag_ForceGenerateJavaOutput="false"

specific_test_case_regex='^-([1-9]+[0-9]*)$'
illegal_case_regex='^-.*$'

#Declaring global variables for paths
test_suit_root="compiler_test_monitor_files/"
test_valid_path="${test_suit_root}tests/valid/"
test_invalid_grammar_path="${test_suit_root}tests/invalid_grammar/"
test_invalid_semantic_path="${test_suit_root}tests/invalid_semantic/"
temp_dotfiles_dir="${test_suit_root}temp_dot_files/"
temp_java_output="${test_suit_root}temp_java_output/"
temp_dotfiles_valid_dir="${temp_dotfiles_dir}valid/"
temp_dotfiles_grammar_dir="${temp_dotfiles_dir}grammar/"
temp_dotfiles_semantic_dir="${temp_dotfiles_dir}semantic/"

#Global variables
tree_dotfile_is_created="true"
CFGs_dotfile_is_created="true"

declare -a test_to_run_arr
test_counter=0
for arg in "$@"
do
    printf "\"$arg\"\n"

    if [[ "$arg" == "-s" && "$flag_compile" == "true" ]];
    then
        flag_compile="false"

    elif [[ "$arg" == "-c" && "$flag_skipClean" == "true" ]];
    then
        flag_skipClean="false"

    elif [[ "$arg" == "--NOMENU" && "$flag_noMenu" == "false" ]];
    then
        flag_noMenu="true"   

    elif [[ "$arg" == "-f" && "$flag_fast" == "false" ]];
    then
        flag_fast="true"
        flag_noMenu="true"  

    elif [[ "$arg" == "-t" && "$flag_onlyTrees" == "false" ]];
    then
        flag_noMenu="true"
        flag_onlyTrees="true"    
        flag_fast="true"    
        flag_skipSemantic="true"
    
    elif [[ "$arg" == "-p" && "$flag_fullPath" == "false" ]];
    then
        flag_fullPath="true"

    elif [[ "$arg" == "-h" && "$flag_help" == "false" ]];
    then
        flag_help="true"

    elif [[ "$arg" == "-hh" && "$flag_ExtraHelp" == "false" ]];
    then
        flag_ExtraHelp="true"

    elif [[ "$arg" == "-e" && "$flag_onlyErrors" == "false" ]];
    then
        flag_onlyErrors="true"
    
    elif [[ "$arg" == "-ss" && "$flag_skipSemantic" == "false" ]];
    then
        flag_skipSemantic="true"
    
    elif [[ "$arg" == "-r" && "$flag_RunInterpreter" == "false" ]];
    then
        flag_RunInterpreter="true"
        
     
    elif [[ "$arg" == "-j" && "$flag_ForceGenerateJavaOutput" == "false" ]];
    then
        flag_ForceGenerateJavaOutput="true"
        flag_RunInterpreter="true"
    
    elif [[ "$arg" == "-l" ]]; #
    then
        printf "\n\n${NO_COL}Listing all the tests found in the test folders:${NO_COL}\n\n"
        counter=1;
        printf "\nValid Tests :\n" ;
        for file in $test_valid_path*;
        do
            printf "\t[$counter]$file \n";
            ((counter=counter+1))
        done

        printf "\n[$counter]Invalid Grammar Tests :\n" ;
        for file in $test_invalid_grammar_path*;
        do
            printf "\t[$counter]$file \n";
            ((counter=counter+1))
        done
    
        printf "\nInvalid Semantics Tests :\n" ;
        for file in $test_invalid_semantic_path*;
        do
            printf "\t[$counter]:$file \n";
            ((counter=counter+1))
        done

        exit 

    elif [[ $arg =~ $specific_test_case_regex ]]; 
    then
        runningTestCases="${BASH_REMATCH[1]}"
        test_to_run_arr[$test_counter]=$runningTestCases
        ((test_counter=test_counter+1))
        flag_specificTest="true"

    elif [[ $arg =~ $illegal_case_regex ]];
    then
        printf "\n\n${RED}Argument '$arg' is either already used or an undefined flag.${NO_COL}\n\n "
        exit
    elif [[ "$flag_specificCompiler" == "false" ]];
    then
        compiler=$arg 
        flag_specificCompiler="true"
        printf "Using this compiler: \"$compiler\"\n "
    else 
        printf "\n\n${RED}Compiler/executable flag was already defined. Dont send in multiple compilers to be used...${NO_COL}\n\n"
        exit
    fi;

done

main() {

DESC_FLAG_H="Shows this info without running the program...\n"
DESC_FLAG_H_H="Shows this info (and alot more) without running the program...\n"
DESC_FLAG_COMPILER="The name of the makefile rule (also needs to be name of the executable).\n"
DESC_FLAG_S_NO_RECOMPILE="Run the the script but do not recompile.\n"
DESC_FLAG_T_ESTCASE="Run the script for any number of given tests.\n"
DESC_FLAG_C_LEAN="Clean before build.\n"
DESC_FLAG_L_IST="List all tests in the test folders.\n"
DESC_FLAG_FAST="Fast run of all tests, skips menu interaction, skips printing line errors.\n"
DESC_FLAG_SKIP_SEMANTIC="Skips the semantic check. Semantic check is slow, so you might want to skip.\n"
DESC_FLAG_E_RRORS_ONLY="Errors Only. Only show test if it fails.\n"
DESC_FLAG_T_REES_ONLY="Generate the trees as fast as possible. \n"
DESC_FLAG_P_ATHS="Show full paths to test-files.\n"
DESC_FLAG_R_UN_INTERPRETER="Run the interpreter for the valid tests...\n"
DESC_FLAG_J_JAVAOUT="Force java to regenerate outputfiles...\n"
DESC_FLAG_MENU="Run program once without prompting the menu.\n"

    if [[ "$flag_ExtraHelp" == "true" ]]; then
        printf "\nInstructions:  ./run_tests.sh [OPTIONS]\n\
DESCRIPTION: \n\
        ${DARKGREEN}Overview:${NO_COL}\n\
            This script will use the makefile to compile (if not telled otherwise)\n\
            the compiler and then use the compiler to compile a set of given\n\
            .java-files. The first time the script is run it will generate a\n\
            required folder struture that will be used to store the java test files,\n\
            the AST and CFG .pdf-files and their respective dot-files.\n\
            In order for the script to successfully generate the folder structure\n\
            make sure that there is no folder in the project root named any of \n\
            the following before running the script: \n\
                tests\n\
                trees\n\
                temp_dot_files\n\n\
            Note that it is up to the user to fill the test folders with test-files.\n\
            For all Java-files in the test folders a indication for wether\n\
            the test FAILED or SUCCEEDED will be reported next to the test-file\n\
            name in the script output. This script checks three types of tests;\n\
            Valid tests, Grammatic tests and Semantic tests. \n\
            Any valid test will be reported as FAILED if it contains a grammatic\n\
            or semantic error.\n\
            Grammtic tests will be reported as FAILED if it is not a grammatic error\n\
            Semantic tests will be reported as FAILED if it does not contain any \n\
            semantic errors. \n\n\
            The folders: \n\
                tests:  \n\
                    Contains subfolders where the the user can store any \n\
                    number of test in order to quickly validated them. \n\n\
                tests/valid:\n\
                        Any Test in this folder will result in FAILURE if \n\
                        it contains either grammatic and/or semantic errors.\n\n\
                tests/invalid_grammar:        \n\
                        Any Test in this folder will result in FAILURE if \n\
                        it does not trigger a Grammatic error.\n\n\
                tests/invalid_semantic:        \n\
                        Any Test in this folder will result in FAILURE if \n\
                        it does not trigger a Semantic error.\n\n\
                trees:\n\
                    Will store the AST and CFG trees generated as .pdf-files. \n\n\
                temp_dot_files:\n\
                    Will store AST and CFG as .dot-files. Main purpouse for \n\
                    storing the .dot-files is to improve script performance.\n\n\
        ${DARKGREEN}What is semantic/grammatic errors?${NO_COL}\n\
            grammatic errors refers to the errors caused by invalid syntax, i.e.\n\
            all errors triggered by the syntax and lexical analysis.\n\
            semantic errors refers to the errors found during semantic analysis.\n\n\
        ${DARKGREEN}How to check if the semantic error is what you expect it to be?${NO_COL}\n\
            When you run a invalid semantic .java-testfile the script will notify \n\
            you wether or not the script triggered a semantic error or not. \n\
            This is useful if you have alot of java-test files where each test\n\
            only contain one semantic error. However in that scenario you must manually\n\
            check that  the error your compiler detects also is the error that should\n\
            be triggered. Instead of checking this manually you can let the script \n\
            do it for you! Simply add a special comment that start with the keyword \n\
            'fail' after the line in the java testfile that contains the semantic \n\
            rule break. Here's a demonstration of how such line in your java test\n\
            file could look like: \n\
                ${GREEN}...//some code here\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a;\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a;${GREEN}//fail Already Declared variable: a\n\
                ${GREEN}...//some code here${NO_COL}\n\
            In the example above the semantic error generated by our compiler would\n\
            be 'Already Declared variable: a', unless our compiler prints this error\n\
            for this line the script will assume that your compiler doesnt work as\n\
            you intended and it will now notify you that this testfile failed.\n\
            If you have a line in your testfile that contains multiple errors you can\n\
            include them by adding several '//fail' comments on the same line, \n\
            this is demonstrated below: \n\
                ${GREEN}...//some code here\n\
                ${DARK_LIGHT_BLUE}int ${LIGHT_BLUE}a1;\n\
                ${DARK_LIGHT_BLUE}boolean ${LIGHT_BLUE}d1;\n\
                ${LIGHT_BLUE}a1 ${FADEDCYAN}= ${LIGHT_BLUE}d1 ${FADEDCYAN}&& ${LIGHT_BLUE}d1;${GREEN}//fail d1: is of wrong type //fail a1 and expression d1 && d1  are of different types\n\
                ${GREEN}...//some code here${NO_COL}\n\
            Note that if a line have multiple errors then either no '//fail' comment can \n\
            be used or all errors on that line must be declared in the '//fail comment'.\n\
            Note that if you omit all '//fail' comment the test will always result \n\
            in a SUCCEED as long as atleast one semantic error exists. \n\
            \n\
        ${DARKGREEN}The interactive script CLI:${NO_COL}\n\
            with the interactive CLI you can get more information of the tests, \n\
            this includes the whole (your) compiler output of any given test-file.\n\
            Given that you configured your compiler accordingly you should \n\
            also be able to view more details about semantic/grammatic errors\n\
            and even where in the test-file the error occoured. \n\n\
        ${DARKGREEN}How to get Semantic Errors listed by the script:${NO_COL}\n\
            The only thing you have to do is to make sure your compiler outputs\n\
            all the semantic errors (seperated, one per line) and to add a \n\
            *specific string* of letters before and after the list of semantic \n\
            errors is printed. Infront of the outputed list there must the following\n\
            'StartOfErrors:' followed by a new line. At the end of the list there\n\
            must be the following 'EndOfErrors'.\n\
            Here is an example of what the output from your compiler should contain:\n\
                StartOfErrors:\n\
                Error[32]: some semantic error you printed that occoured on line 32\n\
                Error[35]: some other semantic error that was triggered on line 35\n\
                EndOfErrors\n\
            In order for the script to show whats on that line in the .java test file\n\
            it is important that the error is given with this specific syntax.\n\
            Specifically that we have the keyword 'Error' followed by brackets  \n\
            containing the linenumber wehre the error occoured, followed by the \n\
            semantic error message. in case you are curious or just know your \n\
            regex, here is the one used to fetch the linenumber (capture group 1)\n\
                .*Error\[\s*([0-9]*)\].*  \n\
            \n\
        ${DARKGREEN}How to get the AST and CFGs trees to be generated by the script.${NO_COL}\n\
            The only thing you need to do is to make sure that your compiler generates\n\
            dot-files for both the AST and CFGs. These files should be named :\n\
                tree.dot    for the AST\n\
                CFGs.dot    for the CFGs\n\
            Note that the CFGs you generate when constructing the intermediate \n\
            representation all needs to be in one single .dot-file for the script\n\
            to generate them. \n\n\
            ----\n\n\
ABOUT THE FLAGS:\n\
            All flags can (mostly) be used in any combination.\n\
[OPTIONS] :\n\
      -h  : ${DESC_FLAG_H}\n\
      -hh : ${DESC_FLAG_H}\
            You are here...\n\n\
      \w  : ${DESC_FLAG_COMPILER}\
            By default the output executable (and Make rule) will be assumed to \n\
            have the name 'compiler', if this is not the case another name can be  \n\
            set using this option. This argument can be a string made up by  \n\
            numbers and/or letters and/or symbols.\n\
            The string may not start with the - symbol, those are reserved for flags.\n\
            The name of the executable must be set in gcc/g++/clang++  \n\
            this is done with the outfile flag (-o). If no such flag is used \n\
            then the executable would be named 'a.out' which the script will have\n\
            no knowledge of. More about the Makefile can be read further down...\n\
                Examples:\n\
                    ./run_tests.sh myCompilerExecutable\n\
                    ./run_tests.sh myOtherCompilerExecutable\n\n\
      -s  : ${DESC_FLAG_S_NO_RECOMPILE}\
            Running this script without this flag will always run make to try to \n\
            build any changed source file. Sometimes you dont want to rebuild even\n\
            though you made changes to the source, that's when this flag will be\n\
            useful.\n\n\
  -[0-9]* : ${DESC_FLAG_T_ESTCASE}\
            Sometimes you just want the result of one or a handful of tests,\n\
            you can use this flag any number of times in order to just show  \n\
            the results of those tests. This is useful if you have alot of tests.\n\
                Examples: \n\
                    ./run_tests.sh myCompiler -6 -7 \n\
                    ./run_tests.sh -1 -5 -7 \n\n\
      -c  : ${DESC_FLAG_C_LEAN}\
            Rather than use the make command to clean your build you can tell this\n\
            script to tell make to clean. This is only useful when you dont want \n\
            to switch between typing 'make clean' and '/run_tests.sh' alot...  \n\n\
      -l  : ${DESC_FLAG_L_IST}\n\
      -f  : ${DESC_FLAG_FAST}\
            Use this option if you just want to make sure that no test fails, \n\
            it is useful when you dont need the functionality the menu brings\n\
            since it's faster and does not make you quit the interactive CLI \n\
            everytime you run the script...\n\
            For a even shorter list, consider combining this flag with -e flag.\n\n\
      -ss : ${DESC_FLAG_SKIP_SEMANTIC}\
            The semantic error checking is slow since it needs to do alot of file\n\
            parsing in order to check if your error occoured on a given line in \n\
            your java test file. Note that only the heavier part is skipped!\n\
            Read more aout this in the description above. \n\n\
      -e  : ${DESC_FLAG_E_RRORS_ONLY}\
            By omitting all succeeded tests you will get a very concise summary\n\
            for only the test that fails. Useful when you have alot of tests\n\
            and just want to focus on the failing cases.\n\
            Consider combining this flag with -f flag for faster result.\n\n\
      -t  : ${DESC_FLAG_T_REES_ONLY}\
            Useful when all you want is your AST and CFG .pdf to update.\n\
            Consider combining with the -[0-9]* flag to only update for a \n\
            specific java test.\n\n\
      -p  : ${DESC_FLAG_P_ATHS}\
            Should not even be a option... but if you want to you can \n\
            show the whole path to a java test file in the script output. \n\n\
      -r  : ${DESC_FLAG_R_UN_INTERPRETER}\
            This flag lets you run your compiler, then run your interpretor\n\
            on your newly created bytecode file (it will also build both). \n\
            During this run you will get notified of how your interpreter \n\
            fared, mainly the exit code and how your interpreters output \n\
            compares to the output of the real java interpretor.  \n\
            Note that you must have Java installed on your system... \n\
                ${RED}NOTE:   As of writing this the interpreter MUST  \n\
                        be named 'interpreter'. ${NO_COL} \n\
             \n\
      -j  : ${DESC_FLAG_J_JAVAOUT}\
            Useful when you need to change your testfiles and therefore need\n\
            to update the cached output from your java tests. \n\
            Combine this flag with the -[0-9]* flag to only update specific  \n\n\
            tests, this could save you some time...  \n\n\
--NOMENU  : ${DESC_FLAG_MENU}\
            It's like the -f flag but slow, not really intended to be used \n\
            by the end user...\n\n\
\n\n"
        exit 0
    fi;
    printf "\nInstructions:  ./run_tests.sh [OPTIONS]\n\
Example: ./run_tests.sh my_compiler -4 -5 -c\n\
[OPTIONS] :\n\
      -h  : ${DESC_FLAG_H}\
      -hh : ${DESC_FLAG_H_H}\
      \w  : ${DESC_FLAG_COMPILER}\
      -s  : ${DESC_FLAG_S_NO_RECOMPILE}\
  -[0-9]* : ${DESC_FLAG_T_ESTCASE}\
      -c  : ${DESC_FLAG_C_LEAN}\
      -l  : ${DESC_FLAG_L_IST}\
      -f  : ${DESC_FLAG_FAST}\
      -ss : ${DESC_FLAG_SKIP_SEMANTIC}\
      -e  : ${DESC_FLAG_E_RRORS_ONLY}\
      -t  : ${DESC_FLAG_T_REES_ONLY}\
      -p  : ${DESC_FLAG_P_ATHS}\
      -r  : ${DESC_FLAG_R_UN_INTERPRETER}\
      -j  : ${DESC_FLAG_J_JAVAOUT}\n\
--NOMENU  : ${DESC_FLAG_MENU}\
\n\n"
    if [[ "$flag_help" == "true" ]]; then
        exit 0
    fi;
    

    #Making sure required filestructured is setup
    folders_exists="true"
    if [[ ! -d "$test_suit_root" ]]; then
        folders_exists="false"

        mkdir "${test_suit_root}"        
    fi;
    if [[ ! -d "$test_valid_path" ]]; then
        folders_exists="false"

        mkdir "${test_suit_root}tests"
        mkdir "$test_valid_path"
        mkdir "$test_invalid_grammar_path"
        mkdir "$test_invalid_semantic_path"
        
    fi;
    if [[ ! -d "${test_suit_root}trees" ]]; then 
        folders_exists="false"
        mkdir "${test_suit_root}trees"
        mkdir "${test_suit_root}trees/invalid"
        mkdir "${test_suit_root}trees/invalid/semantic"
    fi;
    if [[ ! -d "$temp_dotfiles_dir" ]]; then 
        folders_exists="false"
        mkdir "$temp_dotfiles_dir"
        mkdir "$temp_dotfiles_valid_dir"
        mkdir "$temp_dotfiles_grammar_dir"
        mkdir "$temp_dotfiles_semantic_dir"        
    fi;
    if [[ ! -d "$temp_java_output" ]]; then 
        folders_exists="false"
        mkdir "$temp_java_output"   
    fi;
    if [[ "$folders_exists" == "false" ]]; then  #TODO: dubbelkolla denna igen...
        printf "\n${RED}Created folder structures for tests/trees/dot-files, please add some test files! (.java)${NO_COL}\n\n"
        exit  
    fi;

    if [[ "$flag_RunInterpreter" == "true" ]]; then
        if ! command -v java; then
            printf "\n\n${RED}Java was not found! You must install Java to use this feature.${NO_COL}\n"
            printf "\t${DARK_LIGHT_BLUE}Installation guide: \n "
            printf "\tBased on your OS run one of the following lines in your terminal...\n "
            printf "\t\tUbuntu:   \n "
            printf "\t\t\tsudo apt install default-jdk  \n\n"
            printf "\t\tARCH/Manjaro:  \n"
            printf "\t\t\tsudo pacman -S jre-openjdk \n\n"
            printf "${LIGHT_BLUE}If this does not work, google 'how to install java on X' where X is your distro/OS...${NO_COL}\n "
            exit
        fi; 
    fi;
    
   
    printf "Command Used:\n===========================================================\n"
    printf "$0 $args_string\n"
    printf "nr of args: $nr_of_args\n"
    printf "===========================================================\n\n"

    #Declaring the rest of the global variables     
    grammar_output="extra_grammar"
    semantic_output="extra_semantic"
    semantic_output_wlines="extra_semantic_wlines"
    valid_output="extra_valid"
    valid_output_wlines="extra_valid_wlines"
    tempOutput="";
    record_output="";
    record_output_withExtra_grammar="";
    record_output_withExtra_semantic="";
    record_output_withExtra_semantic_wlines="";
    record_output_withExtra_valid="";
    record_output_withExtra_valid_wlines="";

    err_string="Cannot generate a syntax tree for this input"
    succ_string="Tree successfully generated"
    allTestSucceeded="${DARKGREEN}All Test Succeeded, PERFECT!\n${NO_COL}";

    failingTestsString="Extra: \n"

    id_file=1;
    
    if [[ "$flag_compile" == "true"  ]]; then

        if [[ "$flag_skipClean" == "false" ]]; then

            printf "make clean \n===========================================================\n";
            make clean > /dev/null
            printf "===========================================================\n\n";
        else 
            printf "Skipping make clean! \n";
        fi;

        
        if [[ "$flag_specificCompiler" == "true" ]]; then
            printf "make $compiler\n===========================================================\n";
        else 
            printf "make compiler (default case)\n";
            printf "===========================================================\n";            
        fi; 

        make $compiler
        compilerErrorCode=$?

        if [[ "$flag_RunInterpreter" == "true" ]]; then
            make interpreter
        fi;
                
        if [[ $compilerErrorCode != 0 ]];
        then 
            printf "\n${RED}Cancelling script, Compiler exit code was: $compilerErrorCode ${NO_COL}\n"
            
            if [ ! -f "Makefile" ]; then
                printf "${YELLOW}Cause: Makefile is missing\n${NO_COL}"
            else 
            
                missing_make_rules="$(make -qp 2>&1 | awk '/^[a-zA-Z0-9][^$#\/\t=]*:([^=]|$)/ {split($1,A,/ /);for(i in A)print A[i]}' |     sort -u | awk '$1 ~  /compiler:|interpreter:/' | wc -l)"

            
                if [ "${missing_make_rules}" != "2" ]; then
                    printf "${YELLOW}Cause: Makefile needs to define rules for both 'compiler' and 'interpreter'\n${NO_COL}"
                else 
                    printf "${YELLOW}Cause: See make error message above\n${NO_COL}"
                fi; 
            fi;
            printf "\n"
            exit
        fi;
    else 
        printf "Skip running make\n===========================================================\n";
         
    fi; 
    printf "===========================================================\n";

    if [ ! -f "$compiler" ];
    then
        printf "\n${RED}Compier '$compiler' does not exist, did you forget to make it?\n"
        printf "Make sure that the compiler(gcc/clang) uses a '-o' with the value '$compiler', like this '-o$compiler' !\nExiting script.\n\n ${NO_COL}\n\n"
        exit 
    fi;

    #These are used in multiple fucntions of the program, thus globals...
    declare -a outputList
    declare -a outputFileList
    declare -a is_part_of_valid_tests
    declare -a files

    for file in $test_valid_path*;
    do
        is_part_of_valid_tests[$id_file]="$valid_output"
        files[$id_file]="$file"
        ((id_file=id_file+1));
    done
    if [[ "$flag_RunInterpreter" == "false" ]];then
        for file in $test_invalid_grammar_path*;
        do
            is_part_of_valid_tests[$id_file]="$grammar_output"
            files[$id_file]="$file"
            ((id_file=id_file+1));
        done

        for file in $test_invalid_semantic_path*;
        do
            is_part_of_valid_tests[$id_file]="$semantic_output"
            files[$id_file]="$file"
            ((id_file=id_file+1));
        done
    fi;

    #These are used in multiple fucntions of the program, thus globals...
    nrOfTests=$(($id_file - 1))    

    #Fix the number incase a folder is empty...
    if [[ -z "$(ls -A $test_valid_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    
    if [[ -z "$(ls -A $test_invalid_grammar_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    if [[ -z "$(ls -A $test_invalid_semantic_path)" ]];then
        nrOfTests=$(($nrOfTests - 1))
    fi;
    

    if [[ $runningTestCases != "ALL" ]]; then
        output_recorder "\nRunning following testcase: $runningTestCases\n"
        
        for ((test_case=0; test_case <= test_counter; test_case++  ))
        do 

            id_file=${test_to_run_arr[$test_case]}

            if [[ ${is_part_of_valid_tests[$id_file]} == "$valid_output" ]]; then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck Valid Test:"
                else 
                    output_recorder "\n\nCheck Valid Test (Test should succeed... press A for details):"
                fi; 
                run_validTest ${files[$id_file]};
            elif [[ ${is_part_of_valid_tests[$id_file]} == "$grammar_output" ]];
            then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck invalid Grammar Test:"
                else                 
                    output_recorder "\n\nCheck invalid Grammar Test (Test should succeed... press G for details):" ;
                fi; 
                run_invalidGrammarTest ${files[$id_file]};
            elif [[ ${is_part_of_valid_tests[$id_file]} == "$semantic_output" ]];                    
            then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck invalid semantic Test:"
                else                 
                    output_recorder "\n\nCheck invalid semantic Test (Test should succeed... press S for details):" ;
                fi; 
                run_invalidSemanticTest ${files[$id_file]};
            fi;

        done 

        output_recorder "\n\nFinal Status:\n\t$allTestSucceeded\n${NO_COL}";        

    else
        output_recorder "\nRunning following testcases: $runningTestCases\n"
        output_recorder "\nTotal of $nrOfTests valid and invalid tests \n"
        
        id_file=1; #resets id_file

        if [[ ! -z "$(ls -A $test_valid_path)" ]];then
            if [[ "$flag_ForceGenerateJavaOutput" == "false"  && "$flag_RunInterpreter" == "true" ]];then
                output_recorder "\n${YELLOW}OBS: Using cached java output.  ${NO_COL}"
            fi; 
            
            if [[ "$flag_fast" == "true" ]];then
                output_recorder "\n\nCheck Valid Tests:"
            else             
                output_recorder "\n\nCheck Valid Tests: (All test should succeed...):\n${FADEDCYAN}presss A for semantic details, AA for semantic details + errorLine${NO_COL}" ;
            fi; 
            failed_one_test="false"
            for file in $test_valid_path*;
            do
                run_validTest $file;
                #valid_test_succeeded is a global variable
                if [[ "$valid_test_succeeded" == "false" ]]; then
                    failed_one_test="true"
                fi; 
            done
            if [[ "$failed_one_test" == "false" ]]; then
                output_recorder "\n${DARKGREEN}All Valid Test succeeded!!${NO_COL}"
            fi;

        else 
            output_recorder "\n\nNo Valid tests in the $test_valid_path path, add some valid .java files to test them. " ;
        fi; 

        if [[ "$flag_RunInterpreter" == "false" ]];then
            if [[ ! -z "$(ls -A $test_invalid_grammar_path)" ]];then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck invalid Grammar Tests:"
                else             
                    output_recorder "\n\nCheck invalid Grammar Tests: (All test should succeed...):\n${FADEDCYAN}press G for details${NO_COL}" ;
                fi; 
                failed_one_test="false"
                for file in $test_invalid_grammar_path*;
                do
                    run_invalidGrammarTest $file
                    #grammatic_test_succeeded is a global variable
                    if [[ "$grammatic_test_succeeded" == "false" ]]; then
                        failed_one_test="true"
                    fi; 
                done
                if [[ "$failed_one_test" == "false" ]]; then
                    output_recorder "\n${DARKGREEN}All Grammatic Test succeeded!!${NO_COL}"
                fi;
            else 
                output_recorder "\n\nNo Invalid grammatic tests in the $test_invalid_grammar_path path, add some .java files to test them. " ;
            fi; 

            if [[ ! -z "$(ls -A $test_invalid_semantic_path)" ]];then
                if [[ "$flag_fast" == "true" ]];then
                    output_recorder "\n\nCheck invalid semantic Tests:"
                else             
                    output_recorder "\n\nCheck invalid Semantic Tests (All test should succeed...): \n${FADEDCYAN}press S for details, SS for details + errorLine${NO_COL}" ;
                fi; 
                failed_one_test="false"
                for file in $test_invalid_semantic_path*;
                do
                    run_invalidSemanticTest $file
                    #semantic_test_succeeded is a global variable
                    if [[ "$semantic_test_succeeded" == "false" ]]; then
                        failed_one_test="true"
                    fi; 
                done 
                if [[ "$failed_one_test" == "false" ]]; then
                    output_recorder "\n${DARKGREEN}All Invalid Semantic Test succeeded!!${NO_COL}"
                fi; 
            else 
                output_recorder "\n\nNo Invalid semantic tests in the $test_invalid_semantic_path path, add some .java files to test them. " ;
            fi; 
        fi;

        output_recorder "\n\nFinal Status:\n\t$allTestSucceeded\n${NO_COL}";

         if [[ "$flag_ForceGenerateJavaOutput" == "false" && "$flag_RunInterpreter" == "true" ]];then
            output_recorder "\n${YELLOW}Using cached java output. If you make any changes to your java-test files"
            output_recorder "\nyou must update the cache, do this by running the script with the -j flag! \n${NO_COL}"
        fi; 

    fi;

    if [[ ${tree_dotfile_is_created} == "false"   ]];then
        output_recorder "\t${YELLOW}Compiler does not generate a \"tree.dot\" file! \n${NO_COL}";
    fi;

    if [[ "${CFGs_dotfile_is_created}" == "false" ]];then            
        output_recorder "\t${YELLOW}Compiler does not generate a \"CFGs.dot\" file! \n${NO_COL}";
    fi;

    if [[ "${tree_dotfile_is_created}" == "false" || "${CFGs_dotfile_is_created}" == "false" ]];then            
        output_recorder "\t${YELLOW}The dot-files are used to create the graphs. \n${NO_COL}";
    fi;

    if [[ "$flag_noMenu" == "false" ]]; 
    then 
        menu_system
    else
        exit 0
    fi 

    printf "\n";

}

get_line_from_file() {
    file_to_get_line_from="$1"
    line=$2

    line_from_file="$(sed "${line}q;d" $file_to_get_line_from | sed -E 's/^\s*(.*)/\1/g')"
    
    echo "Line[$line]: $line_from_file"
}

get_line_from_string() {
    string_to_get_line_from="$1"
    line=$2

    # TODO: prestanda optimera denna... Vi öppnar filen varje gång vi anropar funktionen... 
    #       Bättre att skicka in var="$(cat $file_to_get_line_from )" och sedan utföra 
    #       operationen på strängen var... 

    line_from_file="$(printf "$string_to_get_line_from" | sed "${line}q;d" | sed -E 's/^\s*(.*)/\1/g')"
    
    echo "Line[$line]: $line_from_file"
}

output_recorder () { #arg1:string to print; arg2:string is in optional info view...


    tempOutput="$1"
    #record_output+="$tempOutput"

    if [[ -n "$2" ]];
    then
        if [[ "$2" == "$semantic_output" ]];
        then
            record_output_withExtra_semantic+="$tempOutput"
            #record_output_withExtra_semantic_wlines+="$tempOutput"
        elif [[ "$2" == "$semantic_output_wlines" ]];
        then            
            record_output_withExtra_semantic_wlines+="$tempOutput"
                    
        elif [[ "$2" == "$grammar_output" ]];
        then
            record_output_withExtra_grammar+="$tempOutput"
        elif [[ "$2" == "$valid_output" ]];
        then
            record_output_withExtra_valid+="$tempOutput"
            #record_output_withExtra_valid_wlines+="$tempOutput"

        elif [[ "$2" == "$valid_output_wlines" ]];
        then
            record_output_withExtra_valid_wlines+="$tempOutput"
            
        fi;
        
    else
        
        record_output+="$tempOutput"
        record_output_withExtra_grammar+="$tempOutput"
        record_output_withExtra_semantic+="$tempOutput"
        record_output_withExtra_semantic_wlines+="$tempOutput"
        record_output_withExtra_valid+="$tempOutput"
        record_output_withExtra_valid_wlines+="$tempOutput"        
        printf "$tempOutput";
    fi;
}

menu_system () {

    printf "\nMENU\n==============================================.\n";
    printf "Type ${DARK_LIGHT_BLUE}a id${NO_COL} to inspect the output for a given test.\n";
    printf "Type ${DARK_LIGHT_BLUE}M${NO_COL} to show default result screen\n";
    printf "Type ${DARK_LIGHT_BLUE}A${NO_COL} to show semantic errors for valid tests\n";
    printf "Type ${DARK_LIGHT_BLUE}G${NO_COL} to show grammatic fail test details\n";
    printf "Type ${DARK_LIGHT_BLUE}S${NO_COL} to show semantic fail test details\n";
    printf "Type ${DARK_LIGHT_BLUE}Q${NO_COL} to exit \n";

    if [ -n "$1" ];
    then
        printf "Error: $1\n"
    fi;

    read  -p "Output selection: " user_input

    printf "\n==============================================\n";

    if [[ "$user_input" == "q" ]];
    then
        printf "\n";
        exit;
    elif [[ "$user_input" == "m" ]];
    then
        printf "$record_output";
        menu_system
    elif [[ "$user_input" == "s" ]];
    then
        printf "$record_output_withExtra_semantic";
        menu_system
    elif [[ "$user_input" == "ss" ]];
    then
        printf "$record_output_withExtra_semantic_wlines";
        menu_system
    elif [[ "$user_input" == "g" ]];
    then
        printf "$record_output_withExtra_grammar";
        menu_system
    elif [[ "$user_input" == "a" ]];
    then
        printf "$record_output_withExtra_valid";
        menu_system
    elif [[ "$user_input" == "aa" ]];
    then
        printf "$record_output_withExtra_valid_wlines";
        menu_system
    else
        if [ $user_input -gt 0 ];
        then        
            if [ $user_input -lt $((nrOfTests+1)) ];
            then
                printf "\n\nThe file below is: [$user_input]:${outputFileList[$user_input]}\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv^\n\n"
                printf "${outputList[$user_input]}"
                printf "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\nThe above file is: [$user_input]:${outputFileList[$user_input]} \n"
                menu_system
            else
                menu_system "user input: \"$user_input\" <-- is invalid"
            fi;
        else
            menu_system "user input: \"$user_input\" <-- is invalid"
        fi;

    fi;

}

run_validTest() {
    result=""
    if [[ "$flag_RunInterpreter" == "false" ]];then
        result=$(./$compiler < $1 2>&1);    
    else 
        result=$(./$compiler "$1" -b    2>&1);  
    fi;

    runtimeErrorCode=$?
    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')
    test_succeeded="false"
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == 0 ]]; then
            test_succeeded="true"
            if [[ "$flag_onlyTrees" == "true" ]]; then
            
                if [[ -f "tree.dot"  ]];then
                    cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                    dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
                else
                    tree_dotfile_is_created="false"
                fi;

                if [[ -f "CFGs.dot" ]];then
                    cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                    dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
                else
                    CFGs_dotfile_is_created="false"
                fi;
   
            fi;
            
            if [[ "$flag_onlyErrors" == "false" ]];then
                output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";
                if [[ "$flag_fullPath" == "true" ]];
                then 
                    output_recorder "\t[$id_file]  $1";
                else 
                    output_recorder "\t[$id_file]  $filename";
                fi;
            fi;

        else                
            allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
        fi;

        if [[ $runtimeErrorCode == 1 ]]; then

            linenumber=$(printf "$result" | tail -n 2 | head -n 1)
            output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;
            output_recorder "\n${RED}  ↳GRAMMAR ERROR($runtimeErrorCode)\n${NO_COL}";
        fi;

        
        if [[ $runtimeErrorCode == 3 ]]; then

            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')      

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;                      

            output_recorder "${YELLOW}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode)${NO_COL}"       
            
        fi;

        if [[ $runtimeErrorCode == 139 ]]; then #Segmentationfault

            output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode) ${NO_COL}\n";        

        fi;

        if [[ $runtimeErrorCode == 134 ]]; then #Assert

            output_recorder "${LIGHT_RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${LIGHT_RED}↳Assert Happened($runtimeErrorCode) ${NO_COL}\n";        

        fi;

        ((id_file=id_file+1));
        valid_test_succeeded="$test_succeeded"
        return
    fi;

    #Full run, with all information
    semantic_errors=$(printf "$result" | grep -Pzo 'StartOfErro(.*\n)*EndOfErrors' | head -n -1 | tail -n +2 | sed -En 's#^(.*)#\t\1#p' )
    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 )
    first_chars=${last_line:0:44}    
    

    if [[  $runtimeErrorCode == 0 ]]; then
        test_succeeded="true"
        
        if [[ "$flag_onlyErrors" == "false" ]];then
            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')           

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_valid_dir$filename.dot
                dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
                dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;
       
            output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";

            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;
            
            if [[ "$flag_RunInterpreter" == "true" ]];then
                #output_recorder "\n\tRunning Interpretor on compiled bytecode"
                interpreter_output="$(./interpreter )" #TODO: Let user pick what interpreter to use... no hardcoding!
                interpreter_runtimeErrorCode=$?
                
                #real_java_output="$(java $1 2>&1)"
                real_java_output=""
                
                if [[ ! -f "${temp_java_output}${filename}_jvm_out" ]]; then
                    real_java_output="$(java $1 2>&1)"
                    printf "$real_java_output" > "${temp_java_output}${filename}_jvm_out" 
                else
                    if [[ "$flag_ForceGenerateJavaOutput" == "true" ]];then
                        real_java_output="$(java $1 2>&1)"
                        printf "$real_java_output" > "${temp_java_output}${filename}_jvm_out"                     
                        
                    fi;
                    real_java_output="$(cat ${temp_java_output}${filename}_jvm_out )"
                fi;

                

                outputList[$id_file]+="${FADEDCYAN}\n\n#################################################\n"
                outputList[$id_file]+="             Output from JVM Interpreter\n"
                outputList[$id_file]+="nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n${NO_COL}"
                outputList[$id_file]+="$real_java_output"

                outputList[$id_file]+="${DARKGREEN}\n\n#################################################\n"
                outputList[$id_file]+="             Output from Interpreter\n"
                outputList[$id_file]+="nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n${NO_COL}"
                #outputList[$id_file]+="$interpreter_output"
                if [[ $interpreter_runtimeErrorCode != 0 ]];then
                    output_recorder "${RED}"
                else 
                    output_recorder "${FADEDCYAN}"
                fi;
                output_recorder "\n\tFinished Interpretor execution, return code: $interpreter_runtimeErrorCode ${NO_COL}"


                

                outputList[$id_file]+="$interpreter_output"
                if [[ "$real_java_output" == "$interpreter_output" ]];then
                    output_recorder "${FADEDCYAN}"
                    output_recorder "\n\tInterpreter output matches output from real java compiler! ${NO_COL}"
                else 
                    output_recorder "${RED}"
                    output_recorder "\n\tInterpreter output does NOT match output from real java compiler! ${NO_COL}"
                fi;                                 
            fi;
        fi;
    else                
        
        allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
    fi;

    
    if [[ $runtimeErrorCode == 1 ]]; then

        linenumber=$(printf "$result" | tail -n 2 | head -n 1)
        output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi; 
        output_recorder "\n${RED}  ↳GRAMMAR ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:46} \n${NO_COL}";
        
        junk=$(rm "${test_suit_root}trees/${1:12}.pdf" > /dev/null  2>&1)
    fi;

    if [[ $runtimeErrorCode == 3 ]]; then

        filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')   
        if [[ -f "tree.dot"  ]];then
            cp tree.dot $temp_dotfiles_valid_dir$filename.dot
            dot -Tpdf $temp_dotfiles_valid_dir$filename.dot -o${test_suit_root}trees/$filename.pdf &
        else
            tree_dotfile_is_created="false"
        fi;

        if [[ -f "CFGs.dot" ]];then
            cp CFGs.dot $temp_dotfiles_valid_dir$filename"(_CFGs)".dot     
            dot -Tpdf $temp_dotfiles_valid_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/$filename"(_CFGs)".pdf &
        else
            CFGs_dotfile_is_created="false"
        fi;

        output_recorder "${YELLOW}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi;       
        
        #output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode):" "$valid_output"        

        print_semantic_error_lines "$1" \
                                        "$semantic_errors"  \
                                        "$valid_output"  \
                                        "$valid_output_wlines"   \
                                        "YELLOW"\
                                        "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
                                        "$valid_output"

        output_recorder "${NO_COL}" "$valid_output"        

    fi;

    if [[ $runtimeErrorCode == 139 ]]; then

        output_recorder "${RED}\n[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi;         

        output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): ${last_line:45} ${NO_COL}\n";
        junk=$(rm "${test_suit_root}trees/${1:12}.pdf" > /dev/null  2>&1)

    fi;

     if [[ $runtimeErrorCode == 134 ]]; then #Assert

            output_recorder "${LIGHT_RED}\n[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;        

            output_recorder "\n  ${LIGHT_RED}↳Assert Happened($runtimeErrorCode) ${NO_COL}\n";        
            treated_assert_str=$(printf "$last_line" | tail -n 1 | awk -F': ' '{s=0;space=" "; for (i=1; i<=NF; i++) {for (j=1;j<i;j++) printf " " ; print "   "space"↳"$i}; }')
            output_recorder "${LIGHT_RED}$treated_assert_str${NO_COL}\n" "$valid_output";        

        fi;

    ((id_file=id_file+1));
    valid_test_succeeded="$test_succeeded"
}

run_invalidGrammarTest() {
    result=$(./$compiler < $1);
    runtimeErrorCode=$?
    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')      
    test_succeeded="false" 
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == 1 ]]; then
            test_succeeded="true"
            if [[ "$flag_onlyErrors" == "false" ]];then
                output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";  
                if [[ "$flag_fullPath" == "true" ]];
                then 
                    output_recorder "\t[$id_file]  $1";
                else 
                    output_recorder "\t[$id_file]  $filename";
                fi;       
            fi;

        else

            output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi; 
            allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
            if [[ $runtimeErrorCode == 139 ]]; then
                output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${NO_COL}\n";
            fi;
        fi;
        
        ((id_file=id_file+1));
        if [[ "$flag_onlyErrors" == "false" ]];then #NOTE: this should never happen, could be removed...
            if [[ $runtimeErrorCode == 1 ]]; then
                linenumber=$(printf "$result" | tail -n 2 | head -n 1)
                output_recorder "\n${GREEN}  ↳GRAMMAR ERROR($runtimeErrorCode)\n${NO_COL}" "$grammar_output";

            fi;
        fi;

        if [[ $runtimeErrorCode == 3 ]]; then    
            output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode)\n${NO_COL}" "$grammar_output"
        fi;
        grammatic_test_succeeded="$test_succeeded"
        return
    fi;

    #Full run, with all information
    semantic_errors=$(printf "$result" | grep -Pzo 'StartOfErro(.*\n)*EndOfErrors' | head -n -1 | tail -n +2 | sed -En 's#^(.*)#\t\1#p')
    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 );
    first_chars=${last_line:0:44}
    if [[  $runtimeErrorCode == 1 ]]; then
        test_succeeded="true"
        if [[ "$flag_onlyErrors" == "false" ]];then
            output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";  
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi;   
        fi;

    else

        output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi; 
        allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
        if [[ $runtimeErrorCode == 139 ]]; then

            output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${last_line:45} ${NO_COL}\n";
        fi;
    fi;
    
    ((id_file=id_file+1));

    if [[ $runtimeErrorCode == 1 ]]; then
        
         if [[ "$flag_onlyErrors" == "false" ]];then
#             linenumber=$(printf "$result" | tail -n 2 | head -n 1)
            last_line_results=$(printf "$result" | tail -n 2 | head -n 1)
            output_recorder "\n${GREEN}  ↳GRAMMAR ERROR($runtimeErrorCode): ${last_line_results} \n${NO_COL}" "$grammar_output";
#             output_recorder "\n${GREEN}  ↳GRAMMAR ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:45} \n${NO_COL}" "$grammar_output";
        fi;

    fi;

    if [[ $runtimeErrorCode == 3 ]]; then
  
        output_recorder "\n${YELLOW}  ↳SEMANTIC ERROR($runtimeErrorCode): \n$semantic_errors\n${NO_COL}" "$grammar_output"
    fi;
    grammatic_test_succeeded="$test_succeeded"
}

run_invalidSemanticTest() {
    result=$(./$compiler < $1);
    runtimeErrorCode=$?
    filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')     
    test_succeeded="true"  
    #Enable fast mode, do not generate trees, compiler output only if test succeededd
    if [[ "$flag_fast" == "true" ]]; then
        if [[  $runtimeErrorCode == 3 ]]; then
            
            strBuffer=""
            if [[ "$flag_onlyErrors" == "false" ]];then   
                #output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";     
                if [[ "$flag_fullPath" == "true" ]];
                then 
                    strBuffer+="\t[$id_file]  $1";
                else 
                    strBuffer+="\t[$id_file]  $filename";
                    
                fi;     
                
            fi;
            semantic_errors=$(printf "$result" | grep -Pzo 'StartOfErro(.*\n)*EndOfErrors' | head -n -1 | tail -n +2 | sed -En 's#^(.*)#\t\1#p' )
            print_semantic_error_lines "$1" \
                                    "$semantic_errors"  \
                                    "$semantic_output"  \
                                    "$semantic_output_wlines"   \
                                    "GREEN"\
                                    "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
                                    "$semantic_output"\
                                    "\n${RED}[$id_file]FAILED: \t${NO_COL}${strBuffer}" \
                                    "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}${strBuffer}"
            #Global variable set in print_semantic_error_lines function: semantic_test_did_not_fail                
            test_succeeded="$semantic_test_did_not_fail"

        else

            output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
            if [[ "$flag_fullPath" == "true" ]];
            then 
                output_recorder "\t[$id_file]  $1";
            else 
                output_recorder "\t[$id_file]  $filename";
            fi; 
            allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
            if [[ $runtimeErrorCode == 139 ]]; then

                output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${NO_COL}\n";
            fi;    
        fi;
        
        ((id_file=id_file+1));

        if [[ $runtimeErrorCode == 1 ]]; then

            linenumber=$(printf "$result" | tail -n 2 | head -n 1 )
            output_recorder "\n${RED}  ↳GRAMMAR ERROR($runtimeErrorCode)\n${NO_COL}" "$semantic_output";
            
        fi;

        if [[ $runtimeErrorCode == 3 ]]; then

            if [[ "$flag_onlyTrees" == "true" ]]; then

                if [[ -f "tree.dot"  ]];then
                    cp tree.dot $temp_dotfiles_semantic_dir$filename.dot
                    dot -Tpdf $temp_dotfiles_semantic_dir$filename.dot -o${test_suit_root}trees/invalid/semantic/$filename.pdf &
                else
                    tree_dotfile_is_created="false"
                fi;

                if [[ -f "CFGs.dot" ]];then
                    cp CFGs.dot $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot    
                    dot -Tpdf $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/invalid/semantic/$filename"(_CFGs)".pdf &
                else
                    CFGs_dotfile_is_created="false"
                fi;
                
            fi;

            #output_recorder "\n${GREEN}  ↳SEMANTIC ERROR($runtimeErrorCode)${NO_COL}" "$semantic_output"

            #output_recorder "\n${GREEN}  ↳SEMANTIC ERROR($runtimeErrorCode): \n$semantic_errors\n${NO_COL}" "$semantic_output"
                    
        fi;
        semantic_test_succeeded="$test_succeeded"
        return
    fi;

    #Full run, with all information
    semantic_errors=$(printf "$result" | grep -Pzo 'StartOfErro(.*\n)*EndOfErrors' | head -n -1 | tail -n +2 | sed -En 's#^(.*)#\t\1#p' )
    outputList[$id_file]="$result"
    outputFileList[$id_file]="$1"
    last_line=$(printf "$result" | tail -n 1 );
    first_chars=${last_line:0:44}
    if [[  $runtimeErrorCode == 3 ]]; then
        test_succeeded="true"
        strBuffer=""
        if [[ "$flag_onlyErrors" == "false" ]];then
            #output_recorder "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}";     
            if [[ "$flag_fullPath" == "true" ]];
            then 
                strBuffer+="\t[$id_file]  $1";
            else 
                strBuffer+="\t[$id_file]  $filename";
            fi;        
      
            filename=$(printf $1 | sed -En 's#.*\/([^/]+)$#\1#p')         

            if [[ -f "tree.dot"  ]];then
                cp tree.dot $temp_dotfiles_semantic_dir$filename.dot
                dot -Tpdf $temp_dotfiles_semantic_dir$filename.dot -o${test_suit_root}trees/invalid/semantic/$filename.pdf &
            else
                tree_dotfile_is_created="false"
            fi;

            if [[ -f "CFGs.dot" ]];then
                cp CFGs.dot $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot    
                dot -Tpdf $temp_dotfiles_semantic_dir$filename"(_CFGs)".dot -o${test_suit_root}trees/invalid/semantic/$filename"(_CFGs)".pdf &
            else
                CFGs_dotfile_is_created="false"
            fi;
    
        fi;
        print_semantic_error_lines "$1" \
                                    "$semantic_errors"  \
                                    "$semantic_output"  \
                                    "$semantic_output_wlines"   \
                                    "GREEN"\
                                    "\n  ↳SEMANTIC ERROR($runtimeErrorCode):"\
                                    "$semantic_output"\
                                    "\n${RED}[$id_file]FAILED: \t${NO_COL}${strBuffer}" \
                                    "\n${GREEN}[$id_file]SUCCESS: \t${NO_COL}${strBuffer}"
        #Global variable set in print_semantic_error_lines function: semantic_test_did_not_fail                
        test_succeeded="$semantic_test_did_not_fail"
        
        output_recorder "${NO_COL}" "$semantic_output"
        output_recorder "${NO_COL}" "$semantic_output_wlines"
    else
        
        output_recorder "\n${RED}[$id_file]FAILED:\t${NO_COL}";
        if [[ "$flag_fullPath" == "true" ]];
        then 
            output_recorder "\t[$id_file]  $1";
        else 
            output_recorder "\t[$id_file]  $filename";
        fi; 
        allTestSucceeded="${RED}Some Test Failed! FAIL\n${NO_COL}"
        if [[ $runtimeErrorCode == 139 ]]; then

            output_recorder "\n  ${RED}↳Segmentation Fault($runtimeErrorCode): (Not a valid fail) ${last_line:45} ${NO_COL}\n";
        fi;    
    fi;
    
    ((id_file=id_file+1));

    if [[ $runtimeErrorCode == 1 ]]; then

        linenumber=$(printf "$result" | tail -n 2 | head -n 1 )
        output_recorder "\n${RED}  ↳GRAMMAR ERROR($runtimeErrorCode): Line${linenumber:9}: ${last_line:45} \n${NO_COL}" "$semantic_output";
        
    fi;

    semantic_test_succeeded="$test_succeeded"
}

print_semantic_error_lines() { 
#This function is messy, its a ugly hack that improve performance somewhat... (Only have to parse source file one time...)
    #arg1: file, 
    #arg2: semantic_errors, 
    #arg3 outputstring (used by output_recorder), 
    #arg4 outstring wlines
    #arg5 Default Color
    #arg6 Message
    #arg7 output_recorder buffer
    #arg8 preMessage if fail
    #arg9 preMessage if success
    
    lineNr=0;
    errors_reported=0;
    
    compiler_line_errors=$(printf  "$2" | awk -F '[][] *:* *'  '{print $2}') #Lines for every error...
    readarray -t error_reported_lines <<<"$compiler_line_errors" #Lines for every error...    
    nrOF_compiler_line_errors=${#error_reported_lines[@]}

    str_buffer_param_3=""
    str_buffer_param_4=""
    
    result_summary="$9"
    semantic_test_did_not_fail="true"
    file="$1"
    file_content="$(cat $file)"
    

    readarray -t error_reported_lines_conent <<<"$2"
    errors_reported=${#error_reported_lines_conent[@]}

    declare -a source_reported_content

    #TODO: rename pick_line_for_awk, I do no longer use AWK here...
    pick_line_for_awk=$(printf "$compiler_line_errors" | sed -En 's#([0-9]*)#\1 #p' | tr -d "\n")
    pick_line_for_awk="${pick_line_for_awk::-1}"

    itr=0
    
    for line in $pick_line_for_awk; do
  
        source_reported_content[$itr]="$(get_line_from_string "$file_content" $line)"
        ((itr = itr + 1))
    done; 

    errors_caught_reported=${#source_reported_content[@]}

    for ((i = 0; i < errors_reported; i++)); do

        #NOTE: Removed last part of condition, do not remember why it was added...
#         if [[ "$flag_skipSemantic" == "false" && "$7" != "$valid_output" ]];then 
        if [[ "$flag_skipSemantic" == "false" ]];then 

            compiler_defined_error=$(printf "${error_reported_lines_conent[$i]}" | sed -E 's#.*Error\[\s*[0-9]*\]:*\s*(.*)\s*#\1#g')
            user_defined_error=$(printf "${source_reported_content[$i]}" | sed -En 's#[^/]*//fail:*\s*(.*)\s*#//fail \1#p')
            fail_did_contain=$(printf "$user_defined_error" | grep -e "//fail *$compiler_defined_error" )

            if [[ -n "$fail_did_contain" || "$user_defined_error" == "//fail " || -z "$user_defined_error" ]];
            then
                if [[ "$flag_onlyErrors" == "false" ]];then
                    temp="\n${GREEN}${error_reported_lines_conent[$i]}${NO_COL}"
                    str_buffer_param_3+="$temp"

                    str_buffer_param_4+="$temp"
                    str_buffer_param_4+="\n\t\t${CYAN}${source_reported_content[$i]}${NO_COL}\n"
                fi;
            
            else
                semantic_test_did_not_fail="false"
                colorOR="${DARK_LIGHT_BLUE}OR${RED}"
                temp="\n${YELLOW}${error_reported_lines_conent[$i]}${NO_COL}"
                temp+="\n\t${RED}Unexpected Semantic Error. \n   \
                \tExpected     : $(printf "$user_defined_error" | sed -e "s#^//fail ##g" -e "s#//fail#\n\t\t\t\t    $(printf ${colorOR})#g")\n  \
                \tRecieved     : $compiler_defined_error\n${NO_COL}"            

                str_buffer_param_3+="$temp"

                str_buffer_param_4+="$temp"
                str_buffer_param_4+="\n\t\t${CYAN}${source_reported_content[$i]}${NO_COL}\n"
    
                result_summary="$8"    
            fi;

        else 

            #if [[ "$flag_onlyErrors" == "false" ]];then
            #TODO: Why did I have this here... ^ 

                #temp="\n${GREEN}$line${NO_COL}"
                temp="\n${GREEN}${error_reported_lines_conent[$i]}${NO_COL}"
                str_buffer_param_3+="$temp"

                str_buffer_param_4+="$temp"
                str_buffer_param_4+="\n\t\t${CYAN}$h${NO_COL}\n"                
            #fi;                        
        fi;
    
    done;


    file_content="$(printf "$file_content" | awk 'NR{print NR" " $0}')"
    if [[ "$flag_skipSemantic" == "false" ]]; then


        userDefinedErrorLines="$(printf "$file_content" | grep '//fail' | sed -En 's#^([0-9]+).*#\1#p'  )"
        temp_str_buffer_param_3=""
        temp_str_buffer_param_4=""

        readarray -t error_lines <<<"$userDefinedErrorLines"
        errors_caught=0
        errors_caught_=$(printf "$userDefinedErrorLines" | sed -n '$=');
        ((errors_caught = errors_caught + errors_caught_)) #Fix in case no userDefinedErrorLines exists...
 

        TB_START=$(date +%s.%N)
        compiler_failed_to_catch_atleast_one_error=0;
        for ((i = 0;  i < $errors_caught; i++)); do
            found=0;
            
            for ((j = 0;  j < $errors_reported && $found == 0 ; j++)); do

                if [[ "${error_lines[$i]}" == "${error_reported_lines[$j]}" ]];then

                    found=1;
                fi;
            done;
            
            if [[ $found == 0 ]];then
                temp="\n\t${YELLOW}Compiler did not report error on line ${error_lines[$i]}${NO_COL}\n"
                temp_str_buffer_param_3+="$temp"
                temp_str_buffer_param_4+="$temp"  
                compiler_failed_to_catch_atleast_one_error=1;                                     
            fi;
        done;

        if [[ $compiler_failed_to_catch_atleast_one_error == 1 ]];then
            semantic_test_did_not_fail="false"
            result_summary="$8"
            temp="\n\t${RED}The compiler did not registers invalid semantic for following lines:${NO_COL}\n"
            str_buffer_param_3+="$temp"
            str_buffer_param_4+="$temp" 
            str_buffer_param_3+="$temp_str_buffer_param_3"
            str_buffer_param_4+="$temp_str_buffer_param_4"            
        fi;
        
    fi;

    ######################
    defaultColor="$5"
    if [[ "$flag_onlyErrors" == "false" || "$semantic_test_did_not_fail" == "false" ]];then

        if [[ "$flag_skipSemantic" == "false" ]];then 
            output_recorder "$result_summary";
        elif [[ "$7" != "$valid_output" ]];then 
             output_recorder "$result_summary \n${YELLOW}  ↳WARNING: Not fully tested, could contain invalid semantic errors";
        fi;

        output_recorder "$6" "$7" #I dont care for the color of that part anymore...
        #output_recorder "${defaultColor}$6" "$7"
    fi;

    output_recorder "$str_buffer_param_3" "$3"
    output_recorder "$str_buffer_param_4" "$4"
}

main $@





