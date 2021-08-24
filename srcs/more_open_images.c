/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_open_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:13 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 18:42:56 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit_img(t_game *game)
{
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "imgs/freedom.xpm",
			&game->img_size.x, &game->img_size.y);
	game->open_exit_img = mlx_xpm_file_to_image(game->mlx, "imgs/exit2.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_enemy_img(t_game *game)
{
	game->enemyImg.right = mlx_xpm_file_to_image(game->mlx, "imgs/voenkom.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemyImg.img = game->enemyImg.right;
}
