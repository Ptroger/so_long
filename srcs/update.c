#include "../includes/so_long.h"

void	move_player(t_base *base)
{
	int	previous;

	previous = base->vars->player_move;
	if (base->vars->going_up == 1)
		move_up(base);
	else if (base->vars->going_down == 1)
		move_down(base);
	else if (base->vars->going_right == 1)
		move_right(base);
	else if (base->vars->going_left == 1)
		move_left(base);
	if (base->vars->player_move > previous)
	{
		ft_putnbr_fd(base->vars->player_move, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	is_exit(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->vars->exits)
	{
		if (base->vars->player.x == base->vars->exit[i].x
			&& base->vars->player.y == base->vars->exit[i].y)
			return (1);
		i++;
	}
	return (0);
}
void	collect(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->vars->colls)
	{
		if (base->vars->player.x == base->vars->coll[i].x
			&& base->vars->player.y == base->vars->coll[i].y)
		{
			base->vars->coll[i].x = -1;
			base->vars->coll[i].y = -1;
			base->vars->collected++;
		}
		i++;
	}
}

void	update(t_base *base)
{
	move_player(base);
	base->vars->is_moving = 0;
	collect(base);
	put_img(base);
	if (is_exit(base) == 1)
	{
		if (base->vars->colls == base->vars->collected)
			destroy_base(base, "finished");
	}
}
