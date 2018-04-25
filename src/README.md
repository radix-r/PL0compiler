## Parser and code generator

Usage:
	Put the files codes.h, lexical.c, lexical.h, main.c, makefile, parser.c, parser.h, and pm0.c into the same directory. Navigate to directory in a Linux environment. Run make to compile the source code. Run the program by executing ./compile <flags> <PL0 file> 
	
	Errors are recorded in errors.txt. Intermediate code is stored in codeFile.txt.
Flags:
	-l : print the list of lexemes/tokens (scanner output) to the screen
	-a : print the generated assembly code (parser/codegen output) to the screen
	-v : print virtual machine execution trace (virtual machine output) to the screen