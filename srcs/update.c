/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:17 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/24 16:20:00 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_animation(t_player *player)
{
	if (player->frameCount == player->frames)
	{
		player->current_img = player->defaultImg;
	}
	else if (player->frameCount >= player->frames * 2)
	{
		player->current_img = player->reverseImg;
		player->frameCount = 0;
	}
	player->frameCount += 1;
}

int	ft_update(t_game *game)
{
	player_animation(&game->player);
	graphics(*game);
	return (1);
}
