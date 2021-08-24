/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:15 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/22 16:24:25 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_player_img(t_game *game)
{
	game->player.defaultImg = mlx_xpm_file_to_image(game->mlx,
			"imgs/djenia.xpm", &game->img_size.x, &game->img_size.y);
	game->player.reverseImg = mlx_xpm_file_to_image(game->mlx,
			"imgs/reverse_jenia.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.defaultImg;
}

static void	open_wall_img(t_game *game)
{
	game->wall_imgs.wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/wallu.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_collectable_img(t_game *game)
{
	game->collects_imgs.current_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/dollars.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_empty_img(t_game *game)
{
	game->empty_img = mlx_xpm_file_to_image(game->mlx,
			"imgs/fon.xpm", &game->img_size.x, &game->img_size.y);
}

void	open_images(t_game *game)
{
	open_player_img(game);
	open_wall_img(game);
	open_collectable_img(game);
	open_empty_img(game);
	open_exit_img(game);
	open_enemy_img(game);
}
