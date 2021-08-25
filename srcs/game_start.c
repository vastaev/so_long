/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:07 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/25 15:29:48 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x + IMG_SIZE / 2 - 20,
			game->wndw_size.y,
			"soooo_long");
	mlx_hook(game->window, 17, 0, end_program, (void *)game);
	open_images(game);
}

static void	anim_setup(t_game *game)
{
	game->player.frames = 25;
	game->player.frameCount = 0;
}

void	start_game(t_infoVars data, t_game *game)
{
	game->moves = 0;
	game->collects = data.legC;
	game->enemyList = NULL;
	game->cellmap = make_cellmap(data, game);
	free_matrix(&data);
	anim_setup(game);
	game_init(game);
}
