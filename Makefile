TEST_EXECUTABLE = Test
CC = g++

INC_DIR = include

OBJ_DIR = obj

SRC_DIR = src

TEST_DIR = testing

CFLAGS = -I$(INC_DIR) -I$(SRC_DIR) -I$(OBJ_DIR) -g -Wall -ansi -pedantic -Wno-write-strings -Wno-parentheses


.SUFFIXES: .cpp .o .C

.C.o:
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$@ $<

.cpp.o:
	$(CC) $(CFLAGS) -c -o $(OBJ_DIR)/$@ $<

TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

TEST_OBJ_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))


OBJFILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

$(info TEST_OBJ_FILES: $(TEST_OBJ_FILES))


$(TEST_EXECUTABLE): $(TEST_OBJ_FILES) $(OBJFILES)
	$(CC) -o $(TEST_EXECUTABLE) $(CFLAGS) $^

$(OBJFILES): $(INC_DIR)/math.h 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -rf $(OBJ_DIR)/*.o *.out $(TEST_EXECUTABLE)
test:
	make clean
	make
	./$(TEST_EXECUTABLE)
.PHONY: clean test
