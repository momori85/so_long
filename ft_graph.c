

#include "so_long.h"

int	ft_create_map(t_vars *vars, t_graph *graph, t_img_map *img)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (vars->map[i])
	{
		if (i != 0 && i % vars->len == 0)
		{
			x = 0;
			y += 64;
		}
		if (vars->map[i] == '1')
			mlx_put_image_to_window(graph->mlx, graph->window, img->img_wall, x, y);
		if (vars->map[i] == '0')
			mlx_put_image_to_window(graph->mlx, graph->window, img->img_wall, x, y);
		x += 64;
		i++;
	}
	return(1);
}

int	img_init(t_img_map *img, t_graph *graph) 
{
	int	size;

	size = 64;
	if ((img->img_path = mlx_new_image(graph->mlx, 64, 64)) == 0)
		return (0);
	img->img_path = mlx_xpm_file_to_image(graph->mlx, "path.xpm", &size, &size);
	if ((img->img_wall = mlx_new_image(graph->mlx, 64, 64)) == 0)
		return (0);
	img->img_wall = mlx_xpm_file_to_image(graph->mlx, "wall.xpm", &size, &size);
	return (1);
}

int	ft_graph_init(t_vars *vars)
{
	t_graph		graph;
	t_img_map	img;

	graph.mlx = mlx_init();
	graph.window = mlx_new_window(graph.mlx, vars->len * 64, ft_strlen(vars->map) / vars->len * 64, "Adventure time");
	if (img_init(&img, &graph) == 0)
		return (0);
	if (ft_create_map(vars, &graph, &img) == 0)
		return (0);
	if (vars->map == NULL)
		return (0);
	sleep(5);
	return (1);
}
