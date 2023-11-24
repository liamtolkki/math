PROJECT = Test
CC = g++

CFLAGS = -g -ggdb -Wall -ansi -pedantic -Wno-write-strings -Wno-parentheses

OBJFILES = differentiation.o testing.o basicMath.o complexNum.o

$(PROJECT): $(OBJFILES)
	$(CC) -o $(PROJECT) $(CFLAGS) $(OBJFILES)

$(OBJFILES): math.h

clean:
	rm -rf *o *.out $(PROJECT)
test:
	make clean
	make
	./$(PROJECT)