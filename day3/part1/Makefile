TARGET = a.out

LIB_DIR = ../..

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu11

INCLUDE_DIR = -I$(LIB_DIR)/include

LIBRARY = -L$(LIB_DIR) -lmy

SOURCES = $(shell find . -type f -name "*.c")

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $^ -o $@ $(LIBRARY)
	rm -f *.o

clean:
	rm -f *.o
	rm -f $(TARGET)

fclean: clean

re: fclean all
