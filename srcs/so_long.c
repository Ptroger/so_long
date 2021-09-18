#include "../includes/so_long.h"
#include <stdlib.h>

int	isber(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

void	routine(t_base *base)
{
	
}

int	main(int ac, char **av)
{
	t_base	*base;

	if (ac != 2 || isber(av[1]) == 0)
	{
		ft_putstr_fd("usage: ./so_long [map.ber]", 2);
		return (-1);
	}
	base = initialise(av[1]);
	mlx_hook(base->win, 17, 1L << 17, close_win, base);
	mlx_hook(base->win, 2, 1L << 0, key_press, base);
	mlx_hook(base->win, 3, 1L << 1, key_release, base);
	put_img(base);
	mlx_loop(base->mlx);
	//mlx_loop_hook(base->mlx, &routine, base);
}
