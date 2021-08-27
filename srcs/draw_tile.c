#include "../includes/so_long.h"

unsigned int	get_pixel(t_data *tile, int x, int y)
{
	printf("addr = %u\n", *(tile->addr + (y * tile->line_length + x * (tile->bits_per_pixel / 8))));

	return (*(tile->addr + (y * tile->line_length + x * (tile->bits_per_pixel / 8))));
}

void	draw_tile(t_base *base, t_start start, t_data *tile)
{
	int 	x;
	int 	y;
	unsigned int	color;

	x = 0;
	printf("H == %d\n", tile->height);
	printf("W == %d\n", tile->width);
	while (x < tile->width)
	{
		y = 0;
		while (y < tile->height)
		{
//			printf("la?\n");
			color = get_pixel(tile, x, y);
//			printf("color == %d\n", color);
			my_mlx_pixel_put(base->img, start.x + x, start.y + y, color);
//			printf("la?\n");
			y++;
		}
		x++;
	}
}