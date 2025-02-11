/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:10 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/11 00:23:57 by lraggio          ###   ########.fr       */
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

void	signal_handle(int signal)
{
	if (signal == SIGINT)
	{
		printf("Olá do sig int");
		exit(NO_ERROR);
	}
	else if (signal == SIGQUIT)
		return ;
}

void	setup_signal_handling()
{
	struct sigaction	sa;

	my_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handle;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		printf("Erro no sigaction");
	}
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_game		game;
	t_player	player;

	my_bzero(&map, sizeof(t_map));
	my_bzero(&player, sizeof(t_player));
	check_args(argc);
	setup_signal_handling();
	my_printf(PINK "Olá! Seja bem-vindo(a) ao início do "
		"nosso projeto! 🦋🐙\n" RESET);
	if (set_map(&map, argv[1]) == ERROR)
		return (ERROR);
	//carregar mapa para alimentar structs com as infos necessárias p/ janela
	start_game(&game, &map, &player);
	clear_map(&map);
}
