#include "../includes/so_long.h"

void	draw_tile(t_base *base, t_start start, t_data *tile)
{
	int x;
	int y;
	char *address

	x = 0;
	y = 0;

	while (x < tile->width)
	{
		while (y < tile->height)
		{
			my_mlx_pixel_put(base->img, start->x + x, start->y + y, )
			y++;
		}
		x++;
	}
}