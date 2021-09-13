#include "../includes/so_long.h"

void	close_win(t_base *base)
{
	destroy_base(base, "finished");
}

void key_press(int keycode, t_base *base)
{
	if (keycode == 65307 || keycode == 119 || keycode == 115
	|| keycode == 97 || keycode == 100)
	{
		if (keycode == 65307)
			close_win(base);
		if (keycode == 119)
			base->vars->going_up = 1;
		if (keycode == 115)
			base->vars->going_down = 1;
		if (keycode == 97)
			base->vars->going_left = 1;
		if (keycode == 100)
			base->vars->going_right = 1;
		update(base);
	}
}

void key_release(int keycode, t_base *base)
{
	if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
	{
		if (keycode == 119)
			base->vars->going_up = 0;
		else if (keycode == 115)
			base->vars->going_down = 0;
		else if (keycode == 97)
			base->vars->going_left = 0;
		else
			base->vars->going_right = 0;
	}
}
