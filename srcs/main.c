#include "so_long.h"

int main(int argc, char *argv[])
{
	t_infoVars	data;
	t_long		program;

	map_validation(argc, argv, &data);
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 800, 600, "SoLong");
	mlx_loop(program.mlx);
	return 0;
}
