#include "../includes/so_long.h"
#include <stdlib.h>

void	destroy_vars(t_vars *vars)
{
	int				i;

	if (vars != 0)
	{
		if (vars->coll != 0)
			free(vars->coll);
		if (vars->map != 0)
		{
			i = 0;
			while (i < vars->height)
				free(vars->map[i++]);
			free(vars->map);
		}
		free(vars);
	}
}
