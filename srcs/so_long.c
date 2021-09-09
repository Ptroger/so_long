#include "../includes/so_long.h"
#include <stdlib.h>
#include "../includes/libft.h"

int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int 	key_hook(int keycode, t_base *base)
{
	(void)keycode;
	(void)base;
	printf("you pressed %d\n", keycode);
	return (1);
}

int	close_win(int keycode, t_base *base)
{
	if (keycode == 53)
	{
		mlx_destroy_image(base->mlx, base->img->img);
		printf("la?\n");
		printf("you pressed %d\n", keycode);
		mlx_destroy_window(base->mlx, base->win);
		exit (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_base	*base;
	int 	toto;

	if (ac != 2 || isber(av[1]) == 0)
	{
		ft_putstr_fd("usage: ./so_long [map.ber]", 2);
		return (-1);
	}
	base = initialise(av[1]);
	put_img(base);
	mlx_key_hook(base->win, key_hook, base);
	toto = mlx_hook(base->win, 2, 1L<<0, close_win, base);
	if (toto == 1)
		return (0);
	mlx_loop(base->mlx);
}
