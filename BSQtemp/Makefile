CFLAGS = -Wall -Werror -Wextra -c
CC = gcc

NAME = BSQ

SRC = findans.c input.c main.c mainutil.c memory.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ 

$(NAME) : $(OBJ) 
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY:clean fclean re $(NAME) all
