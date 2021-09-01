#include "../includes/so_long.h"
#include <stdlib.h>

void	read_map(t_base *base, char *file)
{
	map_width(base, file);
	map_height(base, file);
	map_isvalid(base, file);
	base->game->coll
		= (t_coord *)malloc(sizeof(t_coord) * base->game->count_coll);
	if (base->game->coll == 0)
	{
		free(file);
		destroy_base(base, "map_parsing(): malloc()", errno);
	}
	base->game->map = (int **)malloc(sizeof(int *) * base->game->height);
	if (base->game->map == 0)
	{
		free(file);
		destroy_base(base, "map_parsing(): malloc()", errno);
	}
	parsing_map(base, file);
}