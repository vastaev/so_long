#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include "libft.h"

typedef struct s_infoVars
{
	int		numNL;
	int		legC;
	char	**map;
} t_infoVars;

void	errno_exit(void);
void	error_exit(char *error);

void	error_free_matrix(char *error, char **matrix);

void	map_validation(int argc, char *argv[], t_infoVars *data);

#endif
