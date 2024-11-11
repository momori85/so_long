AR = ar rcs
cc = cc
FLAGS = -Wall -Werror -Wextra
SRC = ft_putchar.c ft_printf.c ft_calloc.c ft_bzero.c ft_itoa.c ft_itoa_long.c ft_putnbr_base.c
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(FLAGS)
	$(AR) $(NAME) -o $(OBJ)
clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ) $(NAME)
re: fclean all
