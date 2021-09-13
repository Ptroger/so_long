#include "../includes/so_long.h"
#include <stdlib.h>

void	check_char(t_base *base, char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1'
		|| c == '0')
	{
		if (c == 'P')
			base->vars->player_number++;
		else if (c == 'E')
			base->vars->exits++;
		else if (c == 'C')
			base->vars->colls++;
	}
	else
		destroy_base(base, "wrong char");
}

void	write_map(t_base *base, char *file)
{
	int		i;
	size_t	n;
	int		j;

	j = -1;
	n = 0;
	while (++j < base->vars->height)
	{
		i = -1;
		while (++i < base->vars->width && file[n])
		{
			if (file[n] == '\n')
				n++;
			base->vars->map[i][j] = file[n];
			n++;
		}
	}
}

void	check_wall(t_base *base, int i, int j)
{
	if (base->vars->map[i][j] != '1')
	{
		if (j == 0 || j == base->vars->height - 1 || i == 0
		|| i == base->vars->width - 1)
			destroy_base(base, "expected wall");
	}
}

void	map_isvalid(t_base *base)
{
	int	i;
	int	j;

	j = -1;
	while (++j < base->vars->height)
	{
		i = -1;
		while (++i < base->vars->width)
		{
			check_wall(base, i, j);
			check_char(base, base->vars->map[i][j]);
		}
	}
}

void	check_map(t_base *base, char *file)
{
	write_map(base, file);
	free(file);
	map_isvalid(base);
	if (base->vars->player_number != 1
		|| base->vars->exits < 1
		|| base->vars->colls < 1)
		destroy_base(base, "Game setup won't work");
}
