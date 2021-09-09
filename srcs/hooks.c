#include "../includes/so_long.h"

void	close_win(t_base *base)
{
	destroy_base(base, "finished");
}

void key_press(int keycode, t_base *base)
{
	if (keycode == 53 || keycode == 13 || keycode == 1
	|| keycode == 0 || keycode == 2)
	{
		if (keycode == 53)
			close_win(base);
		if (keycode == 13)
			base->vars->going_up = 1;
		if (keycode == 1)
			base->vars->going_down = 1;
		if (keycode == 0)
			base->vars->going_left = 1;
		if (keycode == 2)
			base->vars->going_right = 1;
		update(base);
	}
}

void key_release(int keycode, t_base *base)
{
	if (keycode == 53 || keycode == 13 || keycode == 1
		|| keycode == 0 || keycode == 2)
	{
		if (keycode == 13)
			base->vars->going_up = 0;
		else if (keycode == 1)
			base->vars->going_down = 0;
		else if (keycode == 0)
			base->vars->going_left = 0;
		else
			base->vars->going_right = 0;
	}
}