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
# include <stdbool.h>

# define IMG_SIZE 50

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

typedef struct	s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef enum e_celltype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'V',
}	t_celltype;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

typedef struct	s_cell
{
	t_celltype		type;
	t_vector		position;
	struct s_cell	*up;
	struct s_cell	*down;
	struct s_cell	*right;
	struct s_cell	*left;
}				t_cell;

typedef struct s_player
{
	t_cell	*cell;
	void	*current_img;
}				t_player;

typedef struct	s_wall_img
{
	void	*wall;
}				t_wall_img;

typedef struct	s_collectable_img
{
	void	*current_img;
}	t_collect_img;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_cell			**cellmap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	void			*empty_img;
	void			*exit_img;
}	t_game;


void		errno_exit(void);
void		error_exit(char *error);

void		free_cellmap(t_game *game);
void		error_free_matrix(char *error, char **matrix);

void		map_validation(int argc, char *argv[], t_infoVars *data);

t_image 	ft_new_sprite(void *mlx, char *path);

void	start_game(t_infoVars data, t_game *game);
int		end_program(t_game *game);
void	open_images(t_game *game);
void	graphics(t_game game);
int		ft_update(t_game *game);
int		ft_input(int key, t_game *game);
void	open_exit_img(t_game *game);

#endif
