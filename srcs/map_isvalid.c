#include "../includes/so_long.h"
#include <stdlib.h>

static int	isborder(t_base *base, int i)
{
	if (i < base->vars->width
		|| i > (base->vars->width + 1) * (base->vars->height - 1)
		|| i % (base->vars->width + 1) == 0
		|| i % (base->vars->width + 1) == base->vars->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_base *base, char *file, int i)
{
	if (file[i] == 'P')
		base->vars->player_number++;
	else if (file[i] == 'E')
		base->vars->is_exit++;
	else if (file[i] == 'C')
		base->vars->colls++;
	else if (file[i] == '1' || file[i] == '0')
		return ;
	else
	{
		free(file);
		destroy_base(base, "map content is invalid");
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
				destroy_base(base, "map isn't surrounded by walls");
			}
		}
		else
			isvalid(base, file, i);
	}
	if (base->vars->player_number != 1
		|| base->vars->is_exit != 1
		|| base->vars->colls < 1)
	{
		free(file);
		destroy_base(base, "map configuration is invalid");
	}
}
