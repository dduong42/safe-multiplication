CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = mul.c test.c
OBJ = $(SRC:.c=.o)
NAME = test

all: $(NAME)

debug: CFLAGS += -g
debug: re

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
