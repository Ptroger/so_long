#include "../includes/so_long.h"

unsigned int	get_pixel(t_data *img, int x, int y)
{
	return (*(unsigned int *)
		(img->img + (x * img->bits_per_pixel / 8 + y * img->line_length)));
}

void	draw_tile(t_base *base, t_start start, t_data *tile)
{
	int 	x;
	int 	y;
	unsigned int	color;

	x = 0;
	y = 0;
	printf("la?\n");
	while (x < tile->width)
	{
		while (y < tile->height)
		{
			color = get_pixel(tile, x, y);
			my_mlx_pixel_put(base->img, start.x + x, start.y + y, color);
			y++;
		}
		x++;
	}
}