# Compiler
CC = g++

INC = ./include
SRC = ./src
OBJ = ./build
BIN = ./bin

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/main.o $(OBJ)/player.o $(OBJ)/game.o

PROG = $(BIN)/game

all: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/player.o: $(INC)/player.h
	$(CC) $(CPPFLAGS) -c $(SRC)/player.cpp -o $@

$(OBJ)/game.o: $(INC)/game.h $(OBJ)/player.o
	$(CC) $(CPPFLAGS) -c $(SRC)/game.cpp -o $@

$(OBJ)/main.o: $(OBJ)/game.o $(OBJ)/player.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

clean:
	rm -f $(PROG) $(OBJECTS)
