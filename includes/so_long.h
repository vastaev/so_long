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

typedef struct	s_window
{
	void		*reference;
	t_vector	size;
} 				t_window;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}				t_color;

//typedef struct	t_image
//{
//
//};

typedef struct	s_long
{
	void		*mlx;
	t_window	window;
//	t_image		sprite;
	t_vector	sprite_position;
}				t_long;

void		errno_exit(void);
void		error_exit(char *error);

void		error_free_matrix(char *error, char **matrix);

void		map_validation(int argc, char *argv[], t_infoVars *data);

t_window	ft_new_window(void *mlx, int width, int height, char *name);

#endif
