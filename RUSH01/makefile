CC = gcc


OBJECTS = main.o rush.o input.o
SRC = main.c rush.c input.c

TARGET = rush01

$(TARGET): $(OBJECTS) input.h rush.h 
	$(CC) -o $(TARGET) $(OBJECTS)

clean: 
	rm $(OBJECTS) $(TARGET)
