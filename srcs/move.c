#include "../includes/so_long.h"

void	move_up(t_base *base)
{
	int	x;
	int	y;

	x = base->vars->player.x;
	y = base->vars->player.y;
	if (base->vars->map[x][y - 1] == '0')
	{
		base->vars->player.y -= 1;
		base->vars->player_move++;
	}
}

void	move_down(t_base *base)
{
	int	x;
	int	y;

	x = base->vars->player.x;
	y = base->vars->player.y;
	if (base->vars->map[x][y + 1] == '0')
	{
		base->vars->player.y += 1;
		base->vars->player_move++;
	}
}

void	move_left(t_base *base)
{
	int	x;
	int	y;

	x = base->vars->player.x;
	y = base->vars->player.y;
	if (base->vars->map[x - 1][y] == '0')
	{
		base->vars->player.x -= 1;
		base->vars->player_move++;
	}
}

void	move_right(t_base *base)
{
	int	x;
	int	y;

	x = base->vars->player.x;
	y = base->vars->player.y;
	if (base->vars->map[x + 1][y] == '0')
	{
		base->vars->player.x += 1;
		base->vars->player_move++;
	}
}
