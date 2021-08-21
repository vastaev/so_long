/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:09 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/21 04:47:10 by cjoanne          ###   ########.fr       */
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

void	move_to_exit(t_game *game, t_cell *cell)
{
	printf("VICTORY!\n");
	end_program(game);
}

bool	move_to(t_game *game, t_cell *cell)
{
	if (cell->type == EMPTY)
		move_to_empty(game, cell);
	else if (cell->type == COLLECTABLE)
		move_to_collectable(game, cell);
	else if (cell->type == EXIT && game->collects == 0)
		move_to_exit(game, cell);
	else
		return (false);
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
