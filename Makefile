# Makefile for programs in directory 08-Abstract-Data-Types
# ***************************************************************

all: graph

# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined

#CC = clang -I booklib 
#gcc -I..booklib  -o prog   prog.c  ../booklib/cslib.a
CC = gcc -I booklib
CFLAGS = -g

# ***************************************************************
# Entry to bring the package up to date


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    scratch -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

# ***************************************************************
# C compilations

graph.o: graph.c queue.h
	$(CC) $(CFLAGS) -c graph.c
qlist.o: qlist.c queue.h
	$(CC) -c qlist.c



# ***************************************************************
# Executable programs

graph:graph.o qlist.o 
	$(CC) $(CFLAGS) -o graph graph.o qlist.o booklib/cslib.a
