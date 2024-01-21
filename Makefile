PROJECT = Test
CC = g++

CFLAGS = -g -Wall -ansi -pedantic -Wno-write-strings -Wno-parentheses

.SUFFIXES: .cpp .o .C

.C.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<

OBJFILES = differentiation.o testing.o basicMath.o complexNum.o linear.o trig.o

$(PROJECT): $(OBJFILES)
	$(CC) -o $(PROJECT) $(CFLAGS) $(OBJFILES)

$(OBJFILES): math.h

clean:
	rm -rf *.o *.out $(PROJECT)
test:
	make clean
	make
	./$(PROJECT)