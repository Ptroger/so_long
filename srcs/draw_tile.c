#include "../includes/so_long.h"

void	draw_tile(t_base *base, t_coord start, t_data *tile)
{
	int 	x;
	int 	y;
	unsigned int	color;

	x = 0;
	while (x < tile->width)
	{
		y = 0;
		while (y < tile->height)
		{
			color = get_pixel(tile, x, y);
			my_mlx_pixel_put(base->img, (start.x * 40) + x, (start.y * 40) + y, color);
			y++;
		}
		x++;
	}
}