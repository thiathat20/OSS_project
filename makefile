CC = gcc
OBJECT = main.c crud.o board.o
TARGET = board
CFLAGES = -W -Wall

all: $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGES) -o $@ $^

clean:
	rm *.o
	rm $(TARGET)