#include "../includes/so_long.h"
#include <stdlib.h>

static void	free_matrix(t_base *base, char *file, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	base->vars->map = 0;
	free(file);
	destroy_base(base, "map_parsing(): malloc()");
}

static void	get_coord(t_base *base, char *file, int k, int *obj)
{
	if (file[k] == 'P')
	{
		base->vars->player.x = k % (base->vars->width + 1);
		base->vars->player.y = k / (base->vars->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'E')
	{
		base->vars->exit.x = k % (base->vars->width + 1);
		base->vars->exit.y = k / (base->vars->width + 1);
		file[k] = '0';
	}
	else if (file[k] == 'C')
	{
		base->vars->coll[*obj].x = k % (base->vars->width + 1);
		base->vars->coll[*obj].y = k / (base->vars->width + 1);
		file[k] = '0';
		(*obj)++;
	}
}

void	parse_map(t_base *base, char *file)
{
	int				i;
	int				j;
	int				k;
	int				obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < base->vars->height)
	{
		base->vars->map[j] = (int *)malloc(sizeof(int) * base->vars->width);
		if (base->vars->map[j] == 0)
			free_matrix(base, file, base->vars->map, j);
		i = 0;
		while (i < base->vars->width)
		{
			get_coord(base, file, k, &obj);
			base->vars->map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}