#include "../includes/so_long.h"
#include <stdlib.h>

static int	isborder(t_base *base, int i)
{
	if (i < base->game->width
		|| i > (base->game->width + 1) * (base->game->height - 1)
		|| i % (base->game->width + 1) == 0
		|| i % (base->game->width + 1) == base->game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_base *base, char *file, int i)
{
	if (file[i] == 'P')
		base->game->count_player++;
	else if (file[i] == 'E')
		base->game->count_exit++;
	else if (file[i] == 'C')
		base->game->count_coll++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		destroy_base(base, "map content is invalid", 0);
	}
}

void	map_isvalid(t_base *base, char *file)
{
	int				i;

	i = -1;
	while (file[++i] != 0)
	{
		if (file[i] == '\n')
			continue ;
		if (isborder(base, i))
		{
			if (file[i] != '1')
			{
				free(file);
				destroy_base(base, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(base, file, i);
	}
	if (base->game->count_player != 1
		|| base->game->count_exit != 1
		|| base->game->count_coll < 1)
	{
		free(file);
		destroy_base(base, "map configuration is invalid", 0);
	}
}