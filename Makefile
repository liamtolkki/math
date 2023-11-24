PROJECT = MathTest
CC = g++

CFLAGS = -g

OBJFILES = differentiation.o testing.o

$(PROJECT): $(OBJFILES)
	$(CC) -o $(PROJECT) $(CFLAGS) $(OBJFILES)

$(OBJFILES): math.h

clean:
	rm -rf *o *.out $(PROJECT)