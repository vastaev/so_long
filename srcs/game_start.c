#include "so_long.h"

t_cell **memalloc_cellmap(t_infoVars data, t_cell **cellmap)
{
	int	i;
	int	lineLen;

	i = 0;
	cellmap = malloc(sizeof(t_cell *) * data.numNL + 1);
	if (cellmap == NULL)
		error_free_matrix("Malloc error when making cellmap", data.map);
	lineLen = ft_strlen(data.map[0]);
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

t_celltype	get_type(char legend)
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

void	setup_cell(t_cell **cellmap, int x, int y)
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


t_cell **make_cellmap(t_infoVars data)
{
	int		x;
	int		y;
	t_cell	**cellmap;

	cellmap = memalloc_cellmap(data, cellmap);
	y = 0;
	while (y <= data.numNL)
	{
		x = 0;
		while (data.map[y][x] != '\0')
		{
			cellmap[y][x].type = get_type(data.map[y][x]);
			setup_cell(cellmap, x, y);
			x++;
		}
		y++;
	}
	return (cellmap);
}

void	start_game(t_infoVars data)
{
	t_cell	**cellmap;

	cellmap = make_cellmap(data);
}