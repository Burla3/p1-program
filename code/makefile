CC = gcc
PROG = prog
MAIN = p1-program.c
CFLAGS = -Wall
GENDIR = geneticProcess
INCLUDEFILES = jsonParser.c $(GENDIR)/initial.c $(GENDIR)/fitness.c $(GENDIR)/selection.c $(GENDIR)/crossover.c $(GENDIR)/mutation.c
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