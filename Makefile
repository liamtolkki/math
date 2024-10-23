TEST_EXECUTABLE = Test
CC = g++

INC_DIR = ./include

LIB_DIR = ./lib

SCRIPT_DIR = ./scripts

HEADER_GEN_EXE = headerGen

OBJ_DIR = ./obj

SRC_DIR = ./src

TEST_DIR = ./testing

CFLAGS := -DDEVELOPMENT_MODE -I$(INC_DIR) -I$(SRC_DIR) -I$(OBJ_DIR) -fPIC -g -Wall -ansi -pedantic -Wno-write-strings -Wno-parentheses

#installation variables:

#name of archive
LIB_NAME = libmathlib
#prefix for installation
PREFIX = /usr/local
#path to binaries
LIB_DEST = $(PREFIX)/lib
#path to headers
INC_DEST = $(PREFIX)/include/mathlib



.SUFFIXES: .cpp .o .C

.C.o:
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$@ $<

.cpp.o:
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$@ $<

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

HEADER_GEN_FILE = headerList.cpp

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))


OBJFILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(info TEST_OBJ_FILES: $(TEST_OBJ_FILES))


$(TEST_EXECUTABLE): $(TEST_OBJ_FILES) $(OBJFILES)
	$(CC) -o $(TEST_EXECUTABLE) $(CFLAGS) $^

$(OBJFILES): $(INC_DIR)/math.h 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

all: headerGen $(TEST_EXECUTABLE) static shared  #this builds the full project

#static library
static: $(OBJFILES)
	mkdir -p $(LIB_DIR)
	ar rcs $(LIB_DIR)/$(LIB_NAME).a $(OBJFILES)

#shared library
shared: $(OBJFILES)
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -shared -o $(LIB_DIR)/$(LIB_NAME).so $(OBJFILES)

headerGen:
	$(CC) $(SCRIPT_DIR)/$(HEADER_GEN_FILE) -std=c++17 -o $(SCRIPT_DIR)/$(HEADER_GEN_EXE)
	$(SCRIPT_DIR)/$(HEADER_GEN_EXE)



#installation:
install: headerGen static shared
	install -d $(LIB_DEST) $(INC_DEST)
	install -m 644 $(LIB_DIR)/$(LIB_NAME).a $(LIB_DEST)
	install -m 755 $(LIB_DIR)/$(LIB_NAME).so $(LIB_DEST)
	install -m 644 $(INC_DIR)/*.h $(INC_DEST)

#clean will only clean the working directory...
clean:
	rm -rf $(OBJ_DIR) *.out *.a *.so $(TEST_EXECUTABLE) $(LIB_DIR) $(SCRIPT_DIR)/$(HEADER_GEN_EXE)

uninstall:
	rm -f $(LIB_DEST)/$(LIB_NAME).a
	rm -f $(LIB_DEST)/$(LIB_NAME).so
	rm -rf $(INC_DEST)
rebuild: clean all
test: clean all
	./$(TEST_EXECUTABLE)
.PHONY: clean test
