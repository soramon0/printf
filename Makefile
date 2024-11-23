CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB_NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

all: $(LIB_NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
