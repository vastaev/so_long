#include "so_long.h"

int main(int argc, char *argv[])
{
	t_infoVars	data;
	t_game		game;

	map_validation(argc, argv, &data);
	start_game(data, &game);
	mlx_hook(game.window, 2, 0, ft_input, (t_game *)&game);
	mlx_loop_hook(game.mlx, *ft_update, &game);
	mlx_loop(game.mlx);
	return 0;
}
