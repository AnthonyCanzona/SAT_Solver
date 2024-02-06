CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

AST_SRC_DIR = $(SRC_DIR)/AST
AST_OBJ_DIR = $(OBJ_DIR)/AST
AST_INCLUDE_DIR = include/AST

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(AST_SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(filter-out $(AST_SRC_DIR)/%,$(SRC_FILES))) \
            $(patsubst $(AST_SRC_DIR)/%.cpp,$(AST_OBJ_DIR)/%.o,$(filter $(AST_SRC_DIR)/%,$(SRC_FILES)))
EXECUTABLE = $(BIN_DIR)/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(AST_OBJ_DIR)/%.o: $(AST_SRC_DIR)/%.cpp
	@mkdir -p $(AST_OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
