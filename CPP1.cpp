/* Tool chain of CPP program
    1. Text editor .cpp files
    2. Preprocessor handles diretives starting with # and conditional compliation
        removes comments and output will be pure c++ code and extention will be .ii
    3. Compiler converts preprocessed c++ code file int assembly language 
        checking syntax , type error low level instruction 
        extention will be .asm
    4. Assembler converts asm code into machine code producing .obj objet file
        contain binary code 
    5. Linker takes one or more object files and libraries and combines them to create the 
        final executable file (.exe)
        It resolves eternal references (functions call and variables uses across different
        libriarues)
        
    6. Loader is a system program that prepares an exe file for execution
        a. reads the exe from dis and loads it into memory 
        b. allocates memory for the program's code and data section. set up the memory space 
            for program including stack and heap areas
        c. if the program uses dynamic memory allocation or if it is loaded at a different memory 
            address tha it was compiled for the loader adjust the address in the code and data segments
        d. Dynamic or shared libraries -> resolves at runtime and give access the functions and variables 
            in these libraries
        e. finally loader transfer control to the program by jumping to the entry point, allowing 
            the program to start 
            
    7. Section data :- the actual data for each section follows the section headers
        # .text contains the executable code
        # .data contains the initialized gloabal and static variables 
        # .bss contains the uninitialized global and static variables 
        # .rsrc contains the resources such as icons , dialog menus
        # .reloc contains the relocation information for executable */


#include <stdio.h>//preprocessor

int main()
{
    printf("Hello world");
    return 0;
}