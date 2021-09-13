#include "../includes/so_long.h"

void	put_vars(int i, int j, t_base *base, t_coord start)
{
	int	n;

	if (base->vars->exit.x == i && base->vars->exit.y == j)
			draw_tile(base, start, base->exit);
	n = -1;
	while (++n < base->vars->colls)
		if (base->vars->coll[n].x == i && base->vars->coll[n].y == j)
			draw_tile(base, start, base->trumpet);
	if (base->vars->player.x == i && base->vars->player.y == j)
		draw_tile(base, start, base->antouine);
}

void	put_map(t_base *base)
{
	int				i;
	int				j;
	t_coord	start;
	j = 0;
	while (j < base->vars->height)
	{
		i = 0;
		while (i < base->vars->width)
		{
			start.y = j * 64;
			start.x = i * 64;
			if (base->vars->map[j][i] == 1)
				draw_tile(base, start, base->wall);
			else
				draw_tile(base, start, base->floor);
			put_vars(i, j, base, start);
			i++;
		}
		j++;
	}
}

void	put_img(t_base *base)
{
	put_map(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 0, 0);
}
