#include "../includes/so_long.h"

void	init_tiles(t_base *base)
{
	int	*width;
	int	*height;

	width = &(base->antouine->width);
	height = &(base->antouine->height);
	base->antouine = mlx_xpm_file_to_image(base->mlx, "../xpm/antouine.xpm", width, height);
	if (base->antouine == 0)
		printf("clamerde\n");
	printf("icila\n");
	printf("ici\n");
}

