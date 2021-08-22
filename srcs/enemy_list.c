/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 13:41:18 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/22 13:46:53 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	*create_enemy(t_celltype type, t_cell *cell)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		error_exit("Malloc error on creating enemy");
	enemy->cell = cell;
	enemy->eType = type;
	enemy->direction = 0;
	enemy->next = NULL;
	return (enemy);
}

t_enemy	*find_last_enemy(t_enemy *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	add_enemy(t_game *game, t_enemy *enemy)
{
	if (!game->enemyList)
		game->enemyList = enemy;
	else
		find_last_enemy(game->enemyList)->next = enemy;
}
