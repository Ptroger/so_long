#include "../includes/so_long.h"
#include <stdlib.h>

void	free_map(t_base *base, int **m, int size)
{
	int				i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	base->vars->map = 0;
	destroy_base(base, "malloc failed");
}

void	get_elem(t_base *base, int i, int j)
{
	if (base->vars->map[i][j] == 'P')
	{
		base->vars->player.x = i;
		base->vars->player.y = j;
		base->vars->map[i][j] = '0';
	}
	else if (base->vars->map[i][j] == 'E')
	{
		base->vars->exits--;
		base->vars->exit[base->vars->exits].x = i;
		base->vars->exit[base->vars->exits].y = j;
		base->vars->map[i][j] = '0';
	}
	else if (base->vars->map[i][j] == 'C')
	{
		base->vars->colls--;
		base->vars->coll[base->vars->colls].x = i;
		base->vars->coll[base->vars->colls].y = j;
		base->vars->map[i][j] = '0';
	}
}

void	parse_map(t_base *base)
{
	int	i;
	int	j;
	int	colls;
	int	exits;

	colls = base->vars->colls;
	exits = base->vars->exits;
	j = -1;
	while (++j < base->vars->height)
	{
		i = -1;
		while (++i < base->vars->width)
			get_elem(base, i, j);
	}
	base->vars->exits = exits;
	base->vars->colls = colls;
}

void	alloc_map(t_base *base)
{
	int	i;

	i = -1;
	base->vars->map = (int **)malloc(sizeof(int *) * base->vars->width);
	if (base->vars->map == 0)
		destroy_base(base, "malloc failed");
	while (++i < base->vars->width)
	{
		base->vars->map[i] = (int *)malloc(sizeof(int) * base->vars->height);
		if (base->vars->map[i] == 0)
			free_map(base, base->vars->map, i);
	}
}

void	read_map(t_base *base, char *file)
{
	map_dimensions(base, file);
	alloc_map(base);
	check_map(base, file);
	base->vars->coll
		= (t_point *)malloc(sizeof(t_point) * base->vars->colls);
	base->vars->exit
		= (t_point *)malloc(sizeof(t_point) * base->vars->exits);
	if (base->vars->coll == 0 || base->vars->exit == 0)
		destroy_base(base, "malloc failed");
	parse_map(base);
}
