
#ifndef STRUCT_SO_LONG_H
# define STRUCT_SO_LONG_H

# include "so_long.h"

typedef struct s_vars
{
	int	len;
	char	*map;
	int x;
	int y;
	int start;
}	t_vars;

typedef struct s_graph
{
	void	*window;
	void	*mlx;
}	t_graph;

typedef struct s_img_map
{
	void	*img_wall;
	void	*img_path;
	void	*img_c;
}	t_img_map;


#endif
