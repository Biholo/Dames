EXEC = main
CC = gcc
CFLAGS = -std=c17 -Wall -pedantic -g -lncurses

SRC_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/

HEADER = $(addprefix $(INCLUDE_DIR), affichage.h game.h)
OBJECTS = $(addprefix $(BIN_DIR), $(EXEC).o affichage.o game.o)


$(EXEC) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(BIN_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)


clean: 
	rm -f $(BIN_DIR)*.o $(EXEC)
	rm -r $(BIN_DIR)