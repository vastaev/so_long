#include "so_long.h"

int	end_program(t_game *game)
{
	game->cellmap = NULL;
	exit(0);
}
