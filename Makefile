all:
	make re -C /home/amaury/42_cursus/so_long/so_long/printf
	make re -C /home/amaury/42_cursus/so_long/so_long/minilibx-linux
	cc -o jeux *.c minilibx-linux/*.a printf/*.a -Lmlx -lXext -lX11 -Wall -Werror -Wextra
