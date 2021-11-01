CFLAGS = -Wall -Werror -Wextra -c
CC = gcc

TARGET = rush-02

SRC = calculate.c Dict.c main.c util.c split.c split_num.c 
OBJ = $(SRC:.c=.o)

all : $(TARGET)

%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ 

$(TARGET) : $(OBJ) header.h
	$(CC) -o $(TARGET) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re : fclean all

.PHONY:clean fclean re $(TARGET) all
