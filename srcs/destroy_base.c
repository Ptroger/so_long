#include "../includes/so_long.h"
#include <stdlib.h>

void	destroy_base(t_base *base, char *errmsg)
{
	(void)errmsg;
	if (base != 0)
	{
		if (base->floor != 0)
			mlx_destroy_image(base->mlx, base->floor);
		if (base->wall != 0)
			mlx_destroy_image(base->mlx, base->wall);
		if (base->trumpet != 0)
			mlx_destroy_image(base->mlx, base->trumpet);
		if (base->exit != 0)
			mlx_destroy_image(base->mlx, base->exit);
		if (base->antouine != 0)
			mlx_destroy_image(base->mlx, base->antouine);
		if (base->img != 0)
			mlx_destroy_image(base->mlx, base->img);
		if (base->win != 0)
			mlx_destroy_window(base->mlx, base->win);
//		if (base->mlx != 0)
//			mlx_destroy_display(base->mlx);
		if (base->vars != 0)
			destroy_vars(base->vars);
		free(base);
	}
//	die(errmsg, errnum);
}