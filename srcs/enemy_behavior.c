/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_behavior.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 06:21:28 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 19:27:57 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_direction(t_enemy *enemy)
{
	if (enemy->direction == 0)
		enemy->direction = 1;
	else
		enemy->direction = 0;
}

static void	move_enemy_to(t_enemy *enemy, t_cell *cell)
{
	enemy->cell->type = EMPTY;
	cell->type = enemy->eType;
	enemy->cell = cell;
}

static void	move_hor(t_enemy *enemy, t_game *game)
{
	if (enemy->direction == 0)
	{
		if (enemy->cell->left->type == EMPTY)
			move_enemy_to(enemy, enemy->cell->left);
		else if (enemy->cell->left->type == PLAYER)
		{
			printf("Теперь солдат...\n");
			end_program(game);
		}
		else
			change_direction(enemy);
	}
	else if (enemy->direction == 1)
	{
		if (enemy->cell->right->type == EMPTY)
			move_enemy_to(enemy, enemy->cell->right);
		else if (enemy->cell->right->type == PLAYER)
		{
			printf("Здравствуй юность в сапогах!\n");
			end_program(game);
		}
		else
			change_direction(enemy);
	}
}

static void	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->direction == 0)
	{
		if (enemy->cell->up->type == EMPTY)
			move_enemy_to(enemy, enemy->cell->up);
		else if (enemy->cell->up->type == PLAYER)
		{
			printf("Годик не так много...\n");
			end_program(game);
		}
		else
			change_direction(enemy);
	}
	else if (enemy->direction == 1)
	{
		if (enemy->cell->down->type == EMPTY)
			move_enemy_to(enemy, enemy->cell->down);
		else if (enemy->cell->down->type == PLAYER)
		{
			printf("В армии тоже неплохо\n");
			end_program(game);
		}
		else
			change_direction(enemy);
	}
}

void	move_enemies(t_game *game)
{
	t_enemy	*ptr;

	if (!game->enemyList)
		return ;
	ptr = game->enemyList;
	while (1)
	{
		if (ptr->eType == HOR_ENEMY)
			move_hor(ptr, game);
		else if (ptr->eType == VER_ENEMY)
			move_ver(ptr, game);
		if (ptr->next == NULL)
			break ;
		ptr = ptr->next;
	}
}
