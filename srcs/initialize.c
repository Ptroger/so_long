#include "../includes/so_long.h"
#include <stdlib.h>

t_data	*initialise_data(t_base *base)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->img = mlx_new_image(base->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

t_base	*initialise(char *file)
{
	t_base	*base;
	void 	*mlx;
	void 	*win;

	base = (struct s_base*)malloc(sizeof(t_base));
	mlx = malloc(sizeof(void*));
	win = malloc(sizeof(void*));
	(void)(file);
	base->mlx = mlx;
	base->win = win;
	base->mlx = mlx_init();
	base->antouine = initialise_data(base);
	base->exit = initialise_data(base);
	base->floor = initialise_data(base);
	base->trumpet = initialise_data(base);
	base->wall = initialise_data(base);
	base->img = initialise_data(base);
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "so_long");
	init_tiles(base);
	init_vars(base, file);
	return(base);
}
