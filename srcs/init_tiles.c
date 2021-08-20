#include "../includes/so_long.h"

void	init_tiles(t_base *base)
{
	int	width;
	int	height;

	base->antouine = mlx_xpm_file_to_image(base->mlx, relative_path, &width, &height);
	base->antouine->width = width;
	base->antouine->height = height;
}

