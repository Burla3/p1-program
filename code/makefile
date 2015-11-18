CC = gcc

prog: progpart clean

progpart: cleanexe hellofunc.o
	$(CC) -lm p1-program.c hellofunc.o -o prog

hellofunc.o: hellofunc.c hellofunc.c
	$(CC) -c hellofunc.c

clean: 
	$(RM) hellofunc.o

cleanexe:
	$(RM) prog.exe