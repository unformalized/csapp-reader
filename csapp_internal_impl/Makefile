CC = gcc
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = program

CODE = ./src/cpu/mmu.c ./src/disk/code.c ./src/memory/dram.c ./src/memory/inst.c ./src/main.c

SRC = ./src

.PHONY: program
main:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)

run:
	./$(EXE)


