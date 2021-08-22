/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 04:47:11 by cjoanne           #+#    #+#             */
/*   Updated: 2021/08/22 08:33:39 by nephilister      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_infoVars	data;
	t_game		game;

	map_validation(argc, argv, &data);
	start_game(data, &game);
	mlx_hook(game.window, 2, 0, ft_input, (void *)&game);
	mlx_loop_hook(game.mlx, ft_update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
