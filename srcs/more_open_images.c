#include "so_long.h"

void	open_exit_img(t_game *game)
{
	game->exit_img = mlx_xpm_file_to_image(game->mlx,"imgs/exit.xpm",
						 &game->img_size.x, &game->img_size.y);
}
