/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:10 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/07 18:08:20 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc, char **argv)
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

	my_bzero(&map, sizeof(t_map));
	(void)argv;
	if (check_args == ERROR)
		return (ERROR);
	my_printf(PINK "Olá! Seja bem-vindo(a) ao início do nosso projeto! 🦋🐙\n" RESET);
	if (set_map(&map, argv[1]) == ERROR)
		return (ERROR);
	//início do jogo -> declarar inicializações
	//hooks das teclas
	//hook do próprio jogo
	my_clean_vect(map.map);
}