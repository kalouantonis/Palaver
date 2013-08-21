CC = g++

LIBS = 
CFLAGS = -g3 -Wall

INCLUDEDIR = ./include
SRCDIR = ./src

# Directory in which *.o files will be stored
OBJDIR = ./obj
# Directory where executable will be put
DISTDIR = ./bin
# Name of executable
DISTNAME = palaver

all: makedist makeobj build 


build: main.o utils.o process_arguments.o
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/utils.o $(OBJDIR)/process_arguments.o $(LIBS) -o $(DISTDIR)/$(DISTNAME)

main.o: $(SRCDIR)/main.c
	$(CC) $(SRCDIR)/main.c  -c $(CFLAGS) -I$(INCLUDEDIR) -o $(OBJDIR)/main.o

utils.o: $(SRCDIR)/utils.c $(INCLUDEDIR)/utils.h
	$(CC) $(SRCDIR)/utils.c  -c $(CFLAGS) -I$(INCLUDEDIR) -o $(OBJDIR)/utils.o

process_arguments.o: $(SRCDIR)/process_arguments.c $(INCLUDEDIR)/process_arguments.h
	$(CC) $(SRCDIR)/process_arguments.c -c $(CFLAGS) -I$(INCLUDEDIR) -o $(OBJDIR)/process_arguments.o


# Put objects back in to object file
makeobj: 
	-mkdir $(OBJDIR)

makedist:
	-mkdir $(DISTDIR)

cleanall:
	-rm $(OBJDIR)/*.o $(DISTDIR)/$(DISTNAME)
