#include "so_long.h"

static void	draw_image(t_cell cell, t_game game, t_vector pos)
{
	if  (cell.type == WALL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.wall, pos.x, pos.y);
	else if (cell.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);
}

void	graphics(t_game game)
{
	t_cell	cell;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while(game.cellmap[y] != NULL)
	{
		x = 0;
		while (game.cellmap[y][x].type != 0)
		{
			cell = game.cellmap[y][x];
			draw_image(cell, game, cell.position);
			x++;
		}
		y++;
	}
}
