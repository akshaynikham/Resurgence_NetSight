CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

SRC = src/capture/raw_socket.c src/main.c 
OUT = build/NetSight

all:
		$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
		./$(OUT)

clean:
		rm -f $(OUT)