CC = g++

BIN = ./bin
SRC = ./src
OBJ = ./build
INC = ./include

PROG = $(BIN)/Joguinho

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/jogodado.o $(OBJ)/main.o

all: mkdirs $(PROG)

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/main.o: $(SRC)/main.cpp $(OBJ)/jogodado.o $(OBJ)/jogador.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o	

$(OBJ)/jogodado.o: $(SRC)/jogodado.cpp $(INC)/jogodado.h $(OBJ)/jogador.o $(OBJ)/dado.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogodado.cpp -o $(OBJ)/jogodado.o

$(OBJ)/jogador.o: $(SRC)/jogador.cpp $(INC)/jogador.h $(OBJ)/dado.o
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp -o $(OBJ)/jogador.o

$(OBJ)/dado.o: $(SRC)/dado.cpp $(INC)/dado.h
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp -o $(OBJ)/dado.o

clean:
	rm -f $(BIN)/*
	rm -f $(OBJ)/*
