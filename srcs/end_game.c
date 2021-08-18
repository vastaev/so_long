#include "so_long.h"

int	end_program(t_game *game)
{
	free_cellmap(game);
	game->cellmap = NULL;
	exit(0);
}
