all:
	cc *.c minilibx-linux/*.a -Lmlx -lXext -lX11 -Wall -Werror -Wextra
