CC = gcc
OBJECT = main.c user_crud.o post_crud.o board.o
TARGET = board
CFLAGES = -W -Wall

all: $(TARGET)
$(TARGET): $(OBJECT)
	$(CC) $(CFLAGES) -o $@ $^

clean:
	rm *.o
	rm $(TARGET)