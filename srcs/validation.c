#include "so_long.h"

static void	legend_validation(int argc, char *argv[], t_infoVars *data)
{
	char 		buf[2];
	int			legP;
	int			legE;
	int			mapFd;

	legP = 0;
	legE = 0;
	data->numNL = 0;
	data->legC = 0;
	mapFd = open(argv[argc - 1], O_RDONLY);
	while (read(mapFd, buf, 1) != 0)
	{
		buf[1] = '\0';
		if (buf[0] == 'P')
			legP++;
		if (buf[0] == 'C')
			data->legC++;
		if (buf[0] == 'E')
			legE++;
		if (buf[0] == '\n')
			data->numNL++;
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
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[i]) != firstLineLen)
			error_free_matrix("Wrong map format(not rectangle)", data->map);
		i++;
	}
}

void	map_walls_check(t_infoVars *data)
{
	int	i;
	int	lineLen;

	lineLen = (int)ft_strlen(data->map[0]) - 1;
	i = 0;
	while (data->map[0][i] != '\0')
		if (data->map[0][i++] != '1')
			error_free_matrix("Wrong map format(hole in twall)", data->map);
	i = 0;
	while (data->map[data->numNL][i] != '\0')
		if (data->map[data->numNL][i++] != '1')
			error_free_matrix("Wrong map format(hole in bwall)", data->map);
	i = 1;
	while (i < data->numNL)
		if (data->map[i++][0] != '1')
			error_free_matrix("Wrong map format(hole in lwall)", data->map);
	i = 1;
	while (i < data->numNL)
		if (data->map[i++][lineLen] != '1')
			error_free_matrix("Wrong map format(hole in rwall)", data->map);
}

void	map_validation(int argc, char *argv[], t_infoVars *data)
{
	int 	mapNameLen;
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
	i = 0;
	mapFd = open(argv[mapInd], O_RDONLY);
	if (mapFd == -1)
		errno_exit();
	legend_validation(argc, argv, data);
	data->map = (char **)malloc(sizeof(data->map) * (data->numNL + 1));
	while (get_next_line(mapFd, &data->map[i]))
		i++;
	rectangle_map_check(data);
	map_walls_check(data);
}
