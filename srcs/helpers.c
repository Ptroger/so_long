#include "../includes/so_long.h"

unsigned int	get_pixel(t_data *tile, int x, int y)
{
	return (*(unsigned int *)(tile->addr +
	(y * tile->line_length + x * (tile->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
