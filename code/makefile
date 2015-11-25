CC = gcc
EXEC = prog
MAIN = p1-program.c
CFLAGS = -Wall
INCLUDEFILES = jsonParser.c

# Name: Jansson
# Description: Library for encoding, decoding and manipulating JSON data
# Version: 2.7
PREFIX = /usr/local
LIBDIR = ${PREFIX}/lib
INCLUDEDIR = ${PREFIX}/include
LIB = jansson

run: comp
	./$(EXEC).exe

comp: cleanexe
	$(CC) -o $(EXEC) $(MAIN) $(INCLUDEFILES) -L$(LIBDIR) -I$(INCLUDEDIR) -l$(LIB) $(CFLAGS)

cleanexe:
	$(RM) $(EXEC).exe 