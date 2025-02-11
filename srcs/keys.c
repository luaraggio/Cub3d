/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:17:06 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/11 00:16:56 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_key(const char *key_name, const char *color)
{
	printf("A tecla " "%s%s" RESET " foi pressionada.\n", color, key_name);
}

/*int	is_move_key(int keycode)
{
	return ((keycode == UP_KEY || keycode == DOWN_KEY || keycode == DOWN_KEY
			|| keycode == LEFT_KEY || keycode == W_KEY || keycode == A_KEY
			|| keycode == S_KEY || keycode == D_KEY));
}*/

/*void	handle_shift(t_player *player)
{
	player->speed = MOVE_SPEED * 2;
	print_key("SHIFT", PINK);
}*/

int	release_key(int keycode, t_game *game)
{
	if (keycode < 0 || keycode > 7000)
	{
		printf("Deu erro dentro de release_key");
		return (ERROR);
	}
	game->keys[keycode] = false; // Marca a tecla como solta
	return (NO_ERROR);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode < 0 || keycode > 7000)
	{
		printf("Deu erro dentro de press_key");
		return (ERROR);
	}
	game->keys[keycode] = true; // Marca a tecla como pressionada
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == RIGHT_KEY)
		print_key("seta para a direita", PINK);
	else if (keycode == LEFT_KEY)
		print_key("seta para a esquerda", PINK);
	else if (keycode == W_KEY)
		print_key("W", PINK);
	else if (keycode == S_KEY)
		print_key("S", PINK);
	else if (keycode == A_KEY)
		print_key("A", PINK);
	else if (keycode == D_KEY)
		print_key("D", PINK);
	else
		printf(RED "Alguma outra tecla foi pressionada.\n" RESET);
	return (NO_ERROR);
}
