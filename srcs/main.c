#include "so_long.h"

int main(int argc, char *argv[])
{	
	t_long		game;

	// map_validation(argc, argv, &data);
	game.mlx = mlx_init();
	game.window = ft_new_window(game.mlx, 800, 600, "SO! Long");
	game.sprite.reference = mlx_xpm_file_to_image(game.mlx, "./imgs/wall2.xpm", &game.sprite.size.x, &game.sprite.size.y);
	game.sprite_position.x = 5;
	game.sprite_position.y = 5;
	mlx_key_hook(game.window.reference, *ft_input, &game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
	return 0;
}
