

#include "so_long.h"

int	ft_create_map(t_vars *vars, t_graph *graph, t_img_map *img)
{
	int	i;
	int	x;
	int	y;
	int test;
	int count;

	i = 0;
	/*while (vars->map[i])
	{
		if (i != 0 && i % vars->len == 0)
		{
			x = 0;
			y += 64;
		}
		if (vars->map[i] == '1')
			mlx_put_image_to_window(graph->mlx, graph->window, img->img_wall, x, y);
		if (vars->map[i] == '0' || vars->map[i] == 'E' || vars->map[i] == 'P')
			mlx_put_image_to_window(graph->mlx, graph->window, img->img_path, x, y);
		if (vars->map[i] == 'C')
			mlx_put_image_to_window(graph->mlx, graph->window, img->img_c, x, y);
		x += 64;
		i++;
	}*/
	count = 0;
	test = vars->start;
	x = 3 + 2 * i;
	while (i >= 0)
	{
		test -= vars->len - 1;
		i--;
	}
	while (y < x)
	{
		while(count < x)
		{
			if (vars->map[y] == '1')
				mlx_put_image_to_window(graph->mlx, graph->window, img->img_wall, 928 - 64 * x, 508 - 64 * x);
			if (vars->map[y] == '0' || vars->map[y] == 'E' || vars->map[y] == 'P')
				mlx_put_image_to_window(graph->mlx, graph->window, img->img_path, 928 - 64 * x, 508 - 64 * x);
			if (vars->map[y] == 'C')
				mlx_put_image_to_window(graph->mlx, graph->window, img->img_c, 928 - 64 * x, 508 - 64 * x);
			count++;
		}
		count = 0;
		y++;
	}
	return(1);
}

int	img_init(t_img_map *img, t_graph *graph) 
{
	int	size;

	size = 64;
	if ((img->img_path = mlx_new_image(graph->mlx, 64, 64)) == 0)
		return (0);
	img->img_path = mlx_xpm_file_to_image(graph->mlx, "img/path.xpm", &size, &size);
	if ((img->img_wall = mlx_new_image(graph->mlx, 64, 64)) == 0)
		return (0);
	img->img_wall = mlx_xpm_file_to_image(graph->mlx, "img/wall.xpm", &size, &size);
	if ((img->img_c = mlx_new_image(graph->mlx, 64, 64)) == 0)
		return (0);
	img->img_c = mlx_xpm_file_to_image(graph->mlx, "img/c.xpm", &size, &size);
	return (1);
}

int	ft_graph_init(t_vars *vars)
{
	t_graph		graph;
	t_img_map	img;

	vars->start = 1;
	graph.mlx = mlx_init();
	graph.window = mlx_new_window(graph.mlx, 1920, 1080, "Adventure time");
	if (img_init(&img, &graph) == 0)
		return (0);
	while (vars->map[vars->start - 1] != 'P')
		vars->start++;
	if (ft_create_map(vars, &graph, &img) == 0)
		return (0);
	if (vars->map == NULL)
		return (0);
	sleep(5);
	return (1);
}
