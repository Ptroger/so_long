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

typedef struct s_game
{
	int				**map;
	int				height;
	int				width;
	t_coord			*coll;
	int				count_coll;
	int				count_exit;
	int				count_player;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				player_coll;
	t_coord			player;
	t_coord			exit;
}				t_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
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
	t_data	*wall;
	t_data	*exit;
	t_data	*blank;
}				t_base;

typedef struct	s_map {

}				t_map;

void	init_tiles(t_base *base);
void 	draw_tile(t_base *base, t_coord start, t_data *tile);
void	my_mlx_pixel_put(t_data *img, int x, int y, unsigned int color);
unsigned int	get_pixel(t_data *tile, int x, int y);
void	init_map(t_base *base, char *filename);
void	destroy_base(t_base *base, char *errmsg, int errnum);
void	read_map(t_base *base, char *file);
void	map_parse(t_base *base, char *file);
void	map_isvalid(t_base *base, char *file);

#endif