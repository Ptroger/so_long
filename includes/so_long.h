#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 1920
#define HEIGHT 1080

#include <stdio.h>
#include "mlx.h"

typedef struct	s_base {
	void	*mlx;
	void	*win;
}				t_base;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	img_width;
	int 	img_height;
}				t_img;

typedef struct	s_map {

}				t_map;


#endif