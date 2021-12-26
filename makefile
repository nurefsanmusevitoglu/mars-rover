#
# makefile is to build the project and run tests with files under test/ directory
#

SOURCE:=src
BIN:=bin
TEST:=test

all: build run

build:
	@g++ $(SOURCE)/main.cpp \
		$(SOURCE)/rover.cpp \
		$(SOURCE)/handler.cpp \
		-o $(BIN)/main.out

run:
	@for f in $(shell ls ${TEST}); do \
        echo "\nTest #$$f: "; \
		./$(BIN)/main.out $(TEST)/$$f; \
    done