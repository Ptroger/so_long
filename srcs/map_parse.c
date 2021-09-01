#include "../includes/so_long.h"
#include <stdlib.h>

static void	free_matrix(t_base *base, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	base->game->map = 0;
	free(file);
	destroy_base(base, "map_parsing(): malloc()", errno);
}

static void	get_coord(t_base *base, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		base->game->player.x = k % (base->game->width + 1);
		base->game->player.y = k / (base->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		base->game->exit.x = k % (base->game->width + 1);
		base->game->exit.y = k / (base->game->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		base->game->coll[*obj].x = k % (base->game->width + 1);
		base->game->coll[*obj].y = k / (base->game->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	map_parse(t_base *base, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < base->game->height)
	{
		base->game->map[j] = (int *)malloc(sizeof(int) * base->game->width);
		if (base->game->map[j] == 0)
			free_matrix(base, file, base->game->map, j);
		i = 0;
		while (i < base->game->width)
		{
			get_coord(base, file, k, &obj);
			base->game->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}