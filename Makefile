CC = gcc

SRC = $(wildcard *.c) $(wildcard */*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Werror -pedantic -ansi -std=c99 -g

NAME = ragnarok

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

test: all
	./$(NAME) -n Blah -c Warrior

.PHONY: clean fclean test
