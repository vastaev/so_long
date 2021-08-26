/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:05 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/26 15:37:54 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_infoVars *data)
{
	int	i;

	i = 0;
	while (i < data->numNL)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	data->map = NULL;
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

void	free_enemies(t_game *game)
{
	t_enemy	*next;

	if (game->enemyList == NULL)
		return ;
	while (1)
	{
		next = game->enemyList->next;
		free (game->enemyList);
		if (next == NULL)
			break ;
		game->enemyList = next;
	}
}
