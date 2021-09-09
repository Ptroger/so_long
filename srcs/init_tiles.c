#include "../includes/so_long.h"

void	put_tiles(t_base *base, char *path, t_data *tile)
{
	void	*img;
	int 	width;
	int 	height;

	img = mlx_xpm_file_to_image(base->mlx, path, &width, &height);
	tile->img = img;
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel
								,&tile->line_length, &tile->endian);
	if (tile->img == 0)
		printf("jesaispasencore\n");
	else
	{
		tile->width = width;
		tile->height = height;
	}
}

void	init_tiles(t_base *base)
{
	put_tiles(base, "./xpm/antouine.xpm", base->antouine);
	put_tiles(base, "./xpm/trumpet.xpm", base->trumpet);
	put_tiles(base, "./xpm/wall.xpm", base->wall);
	put_tiles(base, "./xpm/floor.xpm", base->floor);
	put_tiles(base, "./xpm/exit.xpm", base->exit);
}
