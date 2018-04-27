CC=gcc
CFLAGS=-I. -g
#DEPS = codes.h
objects = main.o parser.o pm0.o lexical.o

#lex.o parse.o : lex.c parse.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)


compile : $(objects)
	$(CC) -o compile $(objects) $(CFLAGS)

main.o lexical.o parser.o:  codes.h
lexical.o parser.o main.o: lexical.h
parser.o : parser.h
pm0.o parser.o main.o: pm0.h

.PHONY : clean
clean :
	rm compile $(objects)
