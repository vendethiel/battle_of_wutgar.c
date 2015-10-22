CC = clang

SRC = $(wildcard *.c) $(wildcard */*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -Werror -pedantic -std=c99 -g

NAME = ragnarok

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) -n Blah -c Warrior

.PHONY: clean fclean test
