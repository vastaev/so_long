/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cellmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 05:00:44 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/21 05:00:45 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_cell	**memalloc_cellmap(t_infoVars data, t_cell **cellmap)
{
	int	i;
	int	lineLen;

	i = 0;
	cellmap = malloc(sizeof(t_cell *) * (data.numNL + 2));
	if (cellmap == NULL)
		error_free_matrix("Malloc error when making cellmap", data.map);
	lineLen = (int)ft_strlen(data.map[0]);
	while (i <= data.numNL)
	{
		cellmap[i] = malloc(sizeof(t_cell) * lineLen);
		if (cellmap[i] == NULL)
		{
			while (i > 0)
				free(cellmap[--i]);
			error_exit("Malloc error when making cellmap");
		}
		i++;
	}
	return (cellmap);
}

static t_celltype	get_type(char legend)
{
	if (legend == WALL)
		return (WALL);
	if (legend == COLLECTABLE)
		return (COLLECTABLE);
	if (legend == PLAYER)
		return (PLAYER);
	if (legend == EXIT)
		return (EXIT);
	if (legend == ENEMY)
		return (ENEMY);
	return (EMPTY);
}

static void	setup_cell(t_cell **cellmap, int x, int y)
{
	cellmap[y][x].position.x = x * IMG_SIZE;
	cellmap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		cellmap[y][x].up = &cellmap[y - 1][x];
	if (cellmap[y + 1] != NULL)
		cellmap[y][x].down = &cellmap[y + 1][x];
	if (x != 0)
		cellmap[y][x].left = &cellmap[y][x - 1];
	cellmap[y][x].right = &cellmap[y][x + 1];
}

void	set_game_vars(t_cell *cell, t_game *game)
{
	if (cell->type == PLAYER)
		game->player.cell = cell;
}

t_cell	**make_cellmap(t_infoVars data, t_game *game)
{
	int		x;
	int		y;
	t_cell	**cellmap;

	cellmap = NULL;
	cellmap = memalloc_cellmap(data, cellmap);
	y = 0;
	while (y <= data.numNL)
	{
		x = 0;
		while (data.map[y][x] != '\0')
		{
			cellmap[y][x].type = get_type(data.map[y][x]);
			setup_cell(cellmap, x, y);
			set_game_vars(&cellmap[y][x], game);
			x++;
		}
		cellmap[y][x].type = 0;
		y++;
	}
	cellmap[y] = NULL;
	game->wndw_size.x = x * IMG_SIZE;
	game->wndw_size.y = y * IMG_SIZE;
	return (cellmap);
}
