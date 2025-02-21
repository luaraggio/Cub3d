/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:10 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/21 14:05:14 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc)
{
	if (argc != 2)
	{
		my_printf_error(RED "Error\n" "Usage: ./cub3d <map.cub>\n" RESET);
		exit(ERROR);
	}
	return (NO_ERROR);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_game		game;
	t_player	player;

	my_bzero(&map, sizeof(t_map));
	my_bzero(&player, sizeof(t_player));
	my_bzero(&game, sizeof(t_game));
	check_args(argc);
	if (set_map(&map, argv[1]) == ERROR)
		return (ERROR);
	my_printf(PINK "Olá! Seja bem-vindo(a) ao início do "
		"nosso projeto! 🦋🐙\n" RESET);
	play_cub3d(&game, &map, &player);
	clear_map(&map);
}
