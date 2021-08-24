/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 02:53:22 by nephilister       #+#    #+#             */
/*   Updated: 2021/08/24 16:59:42 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_text(t_game game)
{
	char	*str;

	mlx_string_put(game.mlx, game.window,
		game.wndw_size.x - IMG_SIZE / 2.3 - 50,
		IMG_SIZE - IMG_SIZE / 1.5,
		16728128, "steps: ");
	str = ft_itoa(game.moves);
	mlx_string_put(game.mlx, game.window,
		game.wndw_size.x - IMG_SIZE / 2.3 - 5,
		IMG_SIZE - IMG_SIZE / 1.5,
		16728128, str);
	free(str);
}

static void	draw_image(t_cell cell, t_game game, t_vector pos)
{
	if (cell.type == WALL)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.wall, pos.x, pos.y);
	else if (cell.type == EMPTY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.empty_img, pos.x, pos.y);
	else if (cell.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.current_img, pos.x, pos.y);
	else if (cell.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs.current_img, pos.x, pos.y);
	else if (cell.type == EXIT)
	{
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.exit_img, pos.x, pos.y);
		else if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.open_exit_img, pos.x, pos.y);
	}
	else if (cell.type == HOR_ENEMY || cell.type == VER_ENEMY)
		mlx_put_image_to_window(game.mlx, game.window,
			game.enemyImg.img, pos.x, pos.y);
}

void	graphics(t_game game)
{
	t_cell	cell;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.cellmap[y] != NULL)
	{
		x = 0;
		while (game.cellmap[y][x].type != 0)
		{
			cell = game.cellmap[y][x];
			draw_image(cell, game, cell.position);
			x++;
		}
		y++;
	}
	draw_text(game);
}
