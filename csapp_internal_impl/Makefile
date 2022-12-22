CC = clang
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

BIN_HARDWARE = ./.bin/test_hardware
BIN_LINER = ./.bin/test_link

SRC_DIR = ./src

# debug
COMMON = $(SRC_DIR)/common/print.c $(SRC_DIR)/common/convert.c

# hardware
CPU =$(SRC_DIR)/hardware/cpu/mmu.c $(SRC_DIR)/hardware/cpu/isa.c
MEMORY = $(SRC_DIR)/hardware/memory/dram.c

# linker
LINKER = $(SRC_DIR)/linker/parseElf.c

# test
TEST_HARDWARE = $(SRC_DIR)/tests/test_hardware.c
TEST_LINKER = $(SRC_DIR)/tests/test_elf.c

.PHONY:hardware
hardware:
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(COMMON) $(CPU) $(MEMORY) $(TEST_HARDWARE) -o $(BIN_HARDWARE)
	./$(BIN_HARDWARE)

.PHONY:linker
linker:
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(COMMON) $(LINKER) $(TEST_LINKER) -o $(BIN_LINER)
	./$(BIN_LINER)

clean:
	rm -f *.o *~ $(BIN_HARDWARE) $(BIN_LINER)

