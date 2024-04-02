CC=gcc
CFLAGS=-Wall -Wextra -g 
BUILD_DIR=build
SRC_DIR=src

CFILES= $(wildcard $(SRC_DIR)/*.c)
OBJS= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(CFILES))
Target=main


all: $(Target)
	 	 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(Target): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -f $(BUILD_DIR)/*.o $(Target)
