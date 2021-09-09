#include "../includes/so_long.h"
#include <stdlib.h>

void	map_width(t_base *base, char *file)
{
	base->vars->width = 0;
	while (file[base->vars->width] && file[base->vars->width] != '\n')
		base->vars->width++;
	if (base->vars->width == 0 || file[base->vars->width] == 0)
	{
		free(file);
		destroy_base(base, "map file is invalid");
	}
}

void	map_height(t_base *base, char *file)
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
			destroy_base(base, "map format is invalid");
		}
		i += base->vars->width + 1;
		base->vars->height++;
	}
}
