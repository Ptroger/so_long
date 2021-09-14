#include "../includes/so_long.h"

void	draw_tile(t_base *base, t_point start, t_data *tile)
{
	int				x;
	int				y;
	unsigned int	color;

	x = -1;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			color = get_pixel(tile, x, y);
			if (color != 0x000000)
				my_mlx_pixel_put(base->img, (start.x) + x,
					(start.y) + y, color);
		}
	}
}
