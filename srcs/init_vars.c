#include "../includes/so_long.h"
#include <stdlib.h>

void	init_vars(t_base *base, char *file)
{
	base->vars = (t_vars *)malloc(sizeof(t_vars));
	if (base->vars == 0)
		destroy_base(base, "vars_init(): malloc()");
	base->vars->map = 0;
	base->vars->coll = 0;
	base->vars->colls = 0;
	base->vars->is_exit = 0;
	base->vars->player_number = 0;
	base->vars->player_move = 0;
	base->vars->player_up = 0;
	base->vars->player_down = 0;
	base->vars->player_left = 0;
	base->vars->player_right = 0;
	init_map(base, file);
}