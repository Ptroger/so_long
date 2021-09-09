#include "../includes/so_long.h"
#include <stdlib.h>

void	error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
}

void	destroy_base(t_base *base, char *err)
{
	if (base != 0)
	{
		if (base->floor != 0)
			mlx_destroy_image(base->mlx, base->floor->img);
		if (base->wall != 0)
			mlx_destroy_image(base->mlx, base->wall->img);
		if (base->trumpet != 0)
			mlx_destroy_image(base->mlx, base->trumpet->img);
		if (base->exit != 0)
			mlx_destroy_image(base->mlx, base->exit->img);
		if (base->antouine != 0)
			mlx_destroy_image(base->mlx, base->antouine->img);
		if (base->img != 0)
			mlx_destroy_image(base->mlx, base->img->img);
		if (base->win != 0)
			mlx_destroy_window(base->mlx, base->win);
		if (base->vars != 0)
			destroy_vars(base->vars);
		free(base);
	}
	if (ft_strncmp(err, "finished", 8))
		error(err);
	exit(0);
}