/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:19 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/21 04:56:03 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_legens(int *legP, int *legE, char leg, t_infoVars *data)
{
	if (leg == '0' || leg == '1')
		return (1);
	else if (leg == 'P')
		*legP = *legP + 1;
	else if (leg == 'C')
		data->legC++;
	else if (leg == 'E')
		*legE = *legE + 1;
	else if (leg == '\n')
		data->numNL++;
	else
		return (0);
	return (1);
}

static void	legend_validation(int argc, char *argv[], t_infoVars *data)
{
	char		buf[2];
	int			legP;
	int			legE;
	int			mapFd;

	legP = 0;
	legE = 0;
	data->numNL = 0;
	data->legC = 0;
	mapFd = open(argv[argc - 1], O_RDONLY);
	if (mapFd == -1)
		errno_exit();
	while (read(mapFd, buf, 1) != 0)
	{
		buf[1] = '\0';
		if (count_legens(&legP, &legE, buf[0], data) == 0)
			error_exit("Wrong legend format");
	}
	if (legP != 1 || data->legC < 1 || legE < 1)
		error_exit("Wrong map format");
}

static void	rectangle_map_check(t_infoVars *data)
{
	int	i;
	int	firstLineLen;

	i = 1;
	firstLineLen = (int)ft_strlen(data->map[0]);
	while (i <= data->numNL)
	{
		if (ft_strlen(data->map[i]) != firstLineLen)
			error_exit("Not rectangle");
		i++;
	}
}

static void	map_walls_check(t_infoVars *data)
{
	int	i;
	int	lineLen;

	lineLen = (int)ft_strlen(data->map[0]) - 1;
	i = 0;
	while (data->map[0][i] != '\0')
		if (data->map[0][i++] != '1')
			error_free_matrix("Wrong map format(hole in tWall)", data->map);
	i = 0;
	while (data->map[data->numNL][i] != '\0')
		if (data->map[data->numNL][i++] != '1')
			error_free_matrix("Wrong map format(hole in bWall)", data->map);
	i = 1;
	while (i < data->numNL)
		if (data->map[i++][0] != '1')
			error_free_matrix("Wrong map format(hole in lWall)", data->map);
	i = 1;
	while (i < data->numNL)
		if (data->map[i++][lineLen] != '1')
			error_free_matrix("Wrong map format(hole in rWall)", data->map);
}

void	map_validation(int argc, char *argv[], t_infoVars *data)
{
	int		mapNameLen;
	int		mapInd;
	int		mapFd;
	int		i;

	if (argc != 2)
		error_exit("Wrong args number");
	mapInd = argc - 1;
	mapNameLen = (int)ft_strlen(argv[mapInd]);
	if (mapNameLen < 5)
		error_exit("Wrong map name");
	if (ft_strcmp(argv[mapInd] + mapNameLen - 4, ".ber") != 0)
		error_exit("Wrong extension");
	legend_validation(argc, argv, data);
	mapFd = open(argv[mapInd], O_RDONLY);
	if (mapFd == -1)
		errno_exit();
	data->map = (char **)malloc(sizeof(data->map) * (data->numNL + 1));
	i = 0;
	while (get_next_line(mapFd, &data->map[i]))
		i++;
	rectangle_map_check(data);
	map_walls_check(data);
}
