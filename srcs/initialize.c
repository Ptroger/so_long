#include "../includes/so_long.h"
#include <stdlib.h>

void	init_vars(t_base *base, char *file)
{
	base->vars = (t_vars *)malloc(sizeof(t_vars));
	if (base->vars == 0)
		destroy_base(base, "malloc failed");
	base->vars->map = 0;
	base->vars->coll = 0;
	base->vars->colls = 0;
	base->vars->collected = 0;
	base->vars->is_exit = 0;
	base->vars->player_number = 0;
	base->vars->player_move = 0;
	base->vars->going_up = 0;
	base->vars->going_down = 0;
	base->vars->going_left = 0;
	base->vars->going_right = 0;
	base->vars->is_moving = 0;
	init_map(base, file);
}

t_data	*initialise_data(t_base *base, int i)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->init = 0;
	if (i == 0)
	{
		data->img = mlx_new_image(base->mlx, WIDTH, HEIGHT);
		data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
		data->init = 1;
	}
	return (data);
}

t_base	*initialise(char *file)
{
	t_base	*base;

	base = (struct s_base*)malloc(sizeof(t_base));
	(void)(file);
	base->mlx = 0;
	base->win = 0;
	base->antouine = initialise_data(base, 1);
	base->exit = initialise_data(base, 1);
	base->floor = initialise_data(base, 1);
	base->trumpet = initialise_data(base, 1);
	base->wall = initialise_data(base, 1);
	base->img = 0;
	init_vars(base, file);
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "so_long");
	base->mlx = mlx_init();
	base->img = initialise_data(base, 0);
	init_tiles(base);
	return(base);
}
