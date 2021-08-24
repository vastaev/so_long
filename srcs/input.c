/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:09 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 18:41:17 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_empty(t_game *game, t_cell *cell)
{
	cell->type = PLAYER;
	if (game->player.cell->type != EXIT)
		game->player.cell->type = EMPTY;
	game->player.cell = cell;
}

void	move_to_collectable(t_game *game, t_cell *cell)
{
	cell->type = PLAYER;
	game->player.cell->type = EMPTY;
	game->player.cell = cell;
	game->collects--;
}

void	move_to_end(t_game *game, t_cell *cell, char *msg)
{
	printf("%s\n", msg);
	end_program(game);
}

bool	move_to(t_game *game, t_cell *cell)
{
	if (cell->type == EMPTY)
		move_to_empty(game, cell);
	else if (cell->type == COLLECTABLE)
		move_to_collectable(game, cell);
	else if (cell->type == EXIT && game->collects == 0)
		move_to_end(game, cell, "Свобода?");
	else if (cell->type == VER_ENEMY || cell->type == HOR_ENEMY)
		move_to_end(game, cell, "Здравствуй небо в облаках!");
	else
		return (false);
	move_enemies(game);
	return (true);
}

int	ft_input(int key, t_game *game)
{
	bool	moved;

	if (key == ESC)
		end_program(game);
	if (game->player.cell == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.cell->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.cell->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.cell->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.cell->right);
	else
		return (0);
	if (moved)
		printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
