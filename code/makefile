CC = gcc
PROG = prog
MAIN = p1-program.c
CFLAGS = -Wall
INCLUDEFILES = jsonParser.c geneticProcess/initial.c geneticProcess/fitness.c geneticProcess/selection.c geneticProcess/crossover.c geneticProcess/mutation.c
TENSION = .exe

UNAME := $(shell uname)

ifeq ($(UNAME),Linux)
    TENSION = 
endif

# Name: Jansson
# Description: Library for encoding, decoding and manipulating JSON data
# Version: 2.7
PREFIX = /usr/local
LIBDIR = ${PREFIX}/lib
INCLUDEDIR = ${PREFIX}/include
LIB = jansson

run: comp
	./$(PROG)$(TENSION)

comp: cleanexe
	$(CC) -o $(PROG) $(MAIN) $(INCLUDEFILES) -L$(LIBDIR) -I$(INCLUDEDIR) -l$(LIB) $(CFLAGS)

cleanexe:
	$(RM) $(PROG)