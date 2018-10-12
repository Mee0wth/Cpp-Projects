###
### @file - makefile
### @author - David Coons - Group 37
### @description - Makefile for group project
###
### @citation - Based on file by Harlan James, provided in class resources

#
# Project Name
#
PROJ = pred_prey_group_37

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = main.cpp menu.cpp validation.cpp
SRC += board.cpp critter.cpp ant.cpp doodlebug.cpp

#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ).bin

#
# Compiler Flags
#
CFLAGS = -std=gnu++11

#
# Compiler Flags for debugging
#
DEBUGCFLAGS = -Wall -pedantic

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#
# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
#
.PHONY: default run test updateflags debug clean zip

#
# Default Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run the program
#
default: clean $(BIN) 

# 
# Quick clean and run, no debug
#
quickrun: clean run

#
# Run the program
#
run: $(BIN)
	@./$(BIN)

#
# Testing Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
test: clean updateflags $(BIN) debug

#
# Update compiler flags for debugging
# 
updateflags:
	$(eval CFLAGS += $(DEBUGCFLAGS))

#
# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip -D $(PROJ).zip *.cpp *.hpp makefile *.pdf

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)
