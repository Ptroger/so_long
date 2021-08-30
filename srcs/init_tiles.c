#include "../includes/so_long.h"

void	init_tiles(t_base *base)
{
	void *img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(base->mlx, "./xpm/antouine.xpm", &width, &height);
	base->antouine->img = img;
	base->antouine->addr = mlx_get_data_addr(base->antouine->img, &base->antouine->bits_per_pixel,
											 &base->antouine->line_length, &base->antouine->endian);
	if (base->antouine->img == 0)
		printf("clamerde\n");
	else
	{
		base->antouine->width = width;
		base->antouine->height = height;
	}
}
