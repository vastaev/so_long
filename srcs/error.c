#include "so_long.h"

void	error_exit(char *error)
{
	ft_putstr_fd("Error\n", 2);
	if (error)
	{
		ft_putstr_fd(error, 2);
		write(1, "\n", 1);
	}
	exit(-1);
}

void	errno_exit(void)
{
	char	*error_msg;

	write(2, "so_long: ", 9);
	error_msg = strerror(errno);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(errno);
}
