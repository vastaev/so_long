#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include "libft.h"
# include "mlx.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif


typedef struct s_infoVars
{
	int		numNL;
	int		legC;
	char	**map;
} t_infoVars;

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int g;
	int b;
	int a;
}	t_color;

/* all info needed for an image */
typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct	s_long {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_long;


void		errno_exit(void);
void		error_exit(char *error);

void		error_free_matrix(char *error, char **matrix);

void		map_validation(int argc, char *argv[], t_infoVars *data);

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image 	ft_new_sprite(void *mlx, char *path);

int	ft_input(int key, void *param);
int	ft_update (t_long *program);
int	ft_close(void);

t_color	new_color(int r, int g, int b, int a);
void	turn_pixel_to_color(char *pixel, t_color color);
void	turn_img_to_color(t_image *image, t_color color);

#endif
