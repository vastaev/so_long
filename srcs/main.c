#include "so_long.h"

int main(int argc, char *argv[])
{
	t_infoVars	data;
	t_game		game;

	map_validation(argc, argv, &data);
	start_game(data);
	// game.mlx = mlx_init();
	// game.window = ft_new_window(game.mlx, 800, 600, "SO! Long");
	// mlx_key_hook(game.window.reference, *ft_input, &game);
	// mlx_loop_hook(game.mlx, *ft_update, &game);
	// mlx_loop(game.mlx);
	return 0;
}
