#include "../includes/so_long.h"
#include <stdlib.h>

void	read_map(t_base *base, char *file)
{
	map_width(base, file);
	map_height(base, file);
	map_isvalid(base, file);
	base->vars->coll
		= (t_coord *)malloc(sizeof(t_coord) * base->vars->colls);
	if (base->vars->coll == 0)
	{
		free(file);
		destroy_base(base, "map_parsing(): malloc()");
	}
	base->vars->map = (int **)malloc(sizeof(int *) * base->vars->height);
	if (base->vars->map == 0)
	{
		free(file);
		destroy_base(base, "map_parsing(): malloc()");
	}
	parse_map(base, file);
}