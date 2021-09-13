#include "../includes/so_long.h"
#include <stdlib.h>

void	error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
}

void	destroy_vars(t_vars *vars)
{
	int				i;

	if (vars != 0)
	{
		if (vars->coll != 0)
			free(vars->coll);
		if (vars->map != 0)
		{
			i = 0;
			while (i < vars->height)
				free(vars->map[i++]);
			free(vars->map);
		}
		free(vars);
	}
}

void	destroy_image(void *mlx, t_data *data, char *err)
{
	(void)err;
	if (data->init == 1)
		mlx_destroy_image(mlx, data->img);
	free(data);
}	

void	destroy_base(t_base *base, char *err)
{
	if (base != 0)
	{
		printf("\nicici\n");
		if (base->floor != 0)
			destroy_image(base->mlx, base->floor, err);
		if (base->wall != 0)
			destroy_image(base->mlx, base->wall, err);
		if (base->trumpet != 0)
			destroy_image(base->mlx, base->antouine, err);
		if (base->exit != 0)
			destroy_image(base->mlx, base->trumpet, err);
		if (base->antouine != 0)
			destroy_image(base->mlx, base->exit, err);
		if (base->img != 0)
			destroy_image(base->mlx, base->img, err);
		if (base->win != 0)
			mlx_destroy_window(base->mlx, base->win);
		if (base->mlx != 0)
			mlx_destroy_display(base->mlx);
		if (base->vars != 0)
			destroy_vars(base->vars);
		free(base);
	}
	if (ft_strncmp(err, "finished", 8))
		error(err);
	exit(0);
}
