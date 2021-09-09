#include "../includes/so_long.h"

void	put_map(t_base *base)
{
	t_coord	start;

	start.y = 0;
	printf("wifth = %d\n", base->vars->width);
	printf("height = %d\n", base->vars->height);
	while (start.y < base->vars->width)
	{
		start.x = 0;
		while (start.x < base->vars->height)
		{
			printf("x == %d\ny == %d\n", start.x, start.y);
			if (base->vars->map[start.x][start.y] == 1)
				draw_tile(base, start, base->wall);
			else
				draw_tile(base, start, base->floor);
			start.x++;
		}
		start.y++;
	}
}

void	put_img(t_base *base)
{
	put_map(base);
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 0, 0);
}