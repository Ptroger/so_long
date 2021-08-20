#include "../includes/so_long.h"
#include <stdlib.h>

//void 	draw_texture(t_base *base)
//{
//
//}

int 	key_hook(int keycode, t_base *base)
{
	(void)keycode;
	(void)base;
	printf("you pressed %d\n", keycode);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	base->win = mlx_new_window(base->mlx, WIDTH, HEIGHT, "so_long");
	return(base);
}

int	close(int keycode, t_base *base)
{
	if (keycode == 53)
	{
		printf("you pressed %d\n", keycode);
		mlx_destroy_window(base->mlx, base->win);
		exit (0);
	}
	return (0);
}

int	main(void)
{
	t_base	*base;
	void	*img;
	char	*relative_path = "./xpm/tileset_complet.xpm";
	int 	toto;
	int		img_width;
	int		img_height;

	base = initialise_window();
	img_height = HEIGHT;
	img_width = WIDTH;
	mlx_key_hook(base->win, key_hook, base);
	img = mlx_xpm_file_to_image(base->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(base->mlx, base->win, img, 0, 0);
	toto = mlx_hook(base->win, 2, 1L<<0, close, &base);
	if (toto == 1)
		return (0);
	mlx_loop(base->mlx);
}
