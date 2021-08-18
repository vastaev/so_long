#include "so_long.h"

static void	open_player_img(t_game *game)
{
	game->player.current_img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/alek.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_wall_image(t_game *game)
{
	game->wall_imgs.wall = mlx_xpm_file_to_image(game->mlx,
	"imgs/wall2.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_player_img(game);
	open_wall_image(game);
}
