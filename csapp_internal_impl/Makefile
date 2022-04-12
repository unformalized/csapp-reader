CC = gcc-9
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXECUTABLE = csapp

CODE = ./src/cpu/mmu.c ./src/disk/code.c ./src/memory/dram.c ./src/memory/inst.c ./src/main.c

SRC = ./src

.PHONY: csapp
csapp:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f *.o *~ $(EXECUTABLE)

run:
	./$(EXECUTABLE)


