#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 1920
#define HEIGHT 1080

#include <stdio.h>
#include "mlx.h"

typedef struct	s_start {
	int x;
	int y;
}				t_start;

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
void 	draw_tile(t_base *base, t_start start, t_data *tile);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);


#endif