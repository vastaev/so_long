/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:15 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/21 04:57:13 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_player_img(t_game *game)
{
	game->player.current_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/alek.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_wall_img(t_game *game)
{
	game->wall_imgs.wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall2.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_collectable_img(t_game *game)
{
	game->collects_imgs.current_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/tea.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_empty_img(t_game *game)
{
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/floor.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_player_img(game);
	open_wall_img(game);
	open_collectable_img(game);
	open_empty_img(game);
	open_exit_img(game);
}
