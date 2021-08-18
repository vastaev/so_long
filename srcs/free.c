#include "so_long.h"

void	error_free_matrix(char *error, char **matrix)
{
	ft_free_split(matrix);
	error_exit(error);
}

void	free_cellmap(t_game *game)
{
	t_cell	**cellmap;

	cellmap = game->cellmap;
	while (*game->cellmap != NULL)
	{
		free(*game->cellmap);
		game->cellmap++;
	}
	free (cellmap);
}