#include "so_long.h"

void	error_free_matrix(char *error, char **matrix)
{
	ft_free_split(matrix);
	error_exit(error);
}
