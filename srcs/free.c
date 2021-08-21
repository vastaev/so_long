/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:05 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/21 04:48:48 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
