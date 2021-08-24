/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:46:58 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 19:22:24 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_program(t_game *game)
{
	free_cellmap(game);
	game->cellmap = NULL;
	free_enemies(game);
	game->enemyList = NULL;
	exit(0);
}
