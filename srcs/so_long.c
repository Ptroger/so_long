#include "../includes/so_long.h"
#include <stdlib.h>

int 	key_hook(int keycode, t_base *base)
{
	(void)keycode;
	(void)base;
	printf("you pressed %d\n", keycode);
	return (1);
}

t_data	*initialise_data(t_base *base)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->img = mlx_new_image(base->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

t_base	*initialise_window()
{
	t_base	*base;
	void 	*mlx;
	void 	*win;

	base = (struct s_base*)malloc(sizeof(t_base));
	mlx = malloc(sizeof(void*));
	win = malloc(sizeof(void*));
	base->mlx = mlx;
	base->win = win;
	base->mlx = mlx_init();
	base->antouine = initialise_data(base);
	base->img = initialise_data(base);
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "so_long");
	return(base);
}

int	close(int keycode, t_base *base)
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

int	main(void)
{
	t_base	*base;
	t_start	start;
	int 	toto;

	base = initialise_window();
	start.x = 0;
	start.y = 0;
	init_tiles(base);
	draw_tile(base, start, base->antouine);
	mlx_put_image_to_window(base->mlx, base->win, base->img->img, 150, 150);
	mlx_key_hook(base->win, key_hook, base);
	toto = mlx_hook(base->win, 2, 1L<<0, close, base);
	if (toto == 1)
		return (0);
	mlx_loop(base->mlx);
}
