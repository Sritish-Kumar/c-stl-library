CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/array.c
OBJ = $(SRC:.c=.o)
TARGET = libstl.a

all: $(TARGET)

$(TARGET): $(OBJ)
	ar rcs $@ $^

examples: $(TARGET)
	$(CC) $(CFLAGS) examples/example_array.c -L. -lstl -o examples/example_array

clean:
	rm -f $(OBJ) $(TARGET) examples/example_array
