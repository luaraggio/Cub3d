/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:10 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/17 21:21:05 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc)
{
	if (argc != 2)
	{
		my_printf_error(RED "Error\n" "Usage: ./cub3d <map.cub>\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	my_bzero(&map, sizeof(t_map));
	if (check_args(argc) == ERROR)
		return (ERROR);
	my_printf(PINK "Olá! Seja bem-vindo(a) ao início do "
		"nosso projeto! 🦋🐙\n" RESET);
	if (set_map(&map, argv[1]) == ERROR)
		return (ERROR);
	start_game(&game, &map);
	clear_map(&map);
}
