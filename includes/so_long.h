#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 1920
#define HEIGHT 1080

#include <stdio.h>
#include "mlx.h"
#include "libft.h"

typedef struct	s_coord {
	int x;
	int y;
}				t_coord;

typedef struct s_vars
{
	int				**map;
	int				height;
	int				width;
	t_coord			*coll;
	int				colls;
	int 			collected;
	int				is_exit;
	int				player_number;
	int				going_up;
	int				going_down;
	int				going_left;
	int				going_right;
	size_t 			is_moving;
	int				player_move;
	t_coord			player;
	t_coord			exit;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	init;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	width;
	int 	height;
}				t_data;

typedef struct	s_base {
	void	*mlx;
	void	*win;
	t_data 	*img;
	t_data	*antouine;
	t_data	*trumpet;
	t_data	*wall;
	t_data	*exit;
	t_data	*floor;
	t_vars	*vars;
}				t_base;

void	init_tiles(t_base *base);
void 	draw_tile(t_base *base, t_coord start, t_data *tile);
void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);
unsigned int	get_pixel(t_data *tile, int x, int y);
void	init_map(t_base *base, char *file);
void	destroy_base(t_base *base, char *err);
void	destroy_vars(t_vars *vars);
void	read_map(t_base *base, char *file);
void	map_isvalid(t_base *base, char *file);
void	map_width(t_base *base, char *file);
void	map_height(t_base *base, char *file);
t_base	*initialise(char *file);
void	put_img(t_base *base);
void	move_up(t_base *base);
void	move_left(t_base *base);
void	move_down(t_base *base);
void	move_right(t_base *base);
void 	key_press(int keycode, t_base *base);
void 	key_release(int keycode, t_base *base);
void	close_win(t_base *base);
void	update(t_base *base);

#endif
