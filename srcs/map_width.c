#include "../includes/so_long.h"
#include <stdlib.h>

void	map_width(t_base *base, char *file)
{
	base->game->width = 0;
	while (file[base->game->width] && file[base->game->width] != '\n')
		base->game->width++;
	if (base->game->width == 0 || file[base->game->width] == 0)
	{
		free(file);
		destroy_base(base, "map file is invalid", 0);
	}
}