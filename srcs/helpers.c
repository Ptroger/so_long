#include "../includes/so_long.h"

void	get_w(t_base *base, char *file)
{
	base->vars->width = 0;
	while (file[base->vars->width] && file[base->vars->width] != '\n')
		base->vars->width++;
	if (base->vars->width == 0 || file[base->vars->width] == 0)
	{
		free(file);
		destroy_base(base, "Invalid map disposition");
	}
}

void	get_h(t_base *base, char *file)
{
	int				i;
	int				j;

	base->vars->height = 1;
	i = base->vars->width + 1;
	while (file[i] != 0)
	{
		j = 0;
		while (file[i + j] != 0 && file[i + j] != '\n')
			j++;
		if (base->vars->width != j)
		{
			free(file);
			destroy_base(base, "not rectangular");
		}
		i += base->vars->width + 1;
		base->vars->height++;
	}
}

void	map_dimensions(t_base *base, char *file)
{
	get_w(base, file);
	get_h(base, file);
}

unsigned int	get_pixel(t_data *tile, int x, int y)
{
	return (*(unsigned int *)(tile->addr + (y
			* tile->line_length + x * (tile->bits_per_pixel / 8))));
}

void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
