CC=gcc
CFLAGS=-I. -g
#DEPS = codes.h
objects = main.o parser.o pm0.o lexical.o

#lex.o parse.o : lex.c parse.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)


compile : $(objects)
	$(CC) -o compile $(objects) $(CFLAGS)

main.o lexical.o parser.o:  codes.h
lexical.o parser.o : lexical.h
parser.o : parser.h
cdpm0.o :

.PHONY : clean
clean :
	rm compile $(objects)
