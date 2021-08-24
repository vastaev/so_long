/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:03 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 20:08:56 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	error_free_map(t_infoVars *data, char *error)
{
	free_matrix(data);
	error_exit(error);
}
