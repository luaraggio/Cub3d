/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:17:06 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/12 15:02:57 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_key(const char *key_name, const char *color)
{
	printf("A tecla "
			"%s%s" RESET " foi pressionada.\n",
			color,
			key_name);
}

void	handle_shift(t_player *player)
{
	player->move_speed = MOVE_SPEED * 2;
	print_key("SHIFT", PINK);
}

int	release_key(int keycode, t_game *game)
{
	game->keys[keycode] = 0;
	return (NO_ERROR);
}

int	press_key(int keycode, t_game *game, t_player *player)
{
	game->keys[keycode] = 1;
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == L_SHIFT_KEY || keycode == R_SHIFT_KEY)
		handle_shift(player);
	else if (keycode == RIGHT_KEY)
	{
		// girar p/ direita
		print_key("seta para a direita", PINK);
	}
	else if (keycode == LEFT_KEY)
	{
		// girar p/ esquerda
		print_key("seta para a esquerda", PINK);
	}
	else if (keycode == W_KEY)
	{
		move_player_forward(player);
		print_key("W", PINK);
	}
	else if (keycode == S_KEY)
	{
		move_player_backward(player);
		print_key("S", PINK);
	}
	else if (keycode == A_KEY)
	{
		turn_player_to_left(player);
		print_key("A", PINK);
	}
	else if (keycode == D_KEY)
	{
		turn_player_to_right(player);
		print_key("D", PINK);
	}
	else
		printf(RED "Alguma outra tecla foi pressionada.\n" RESET);
	return (NO_ERROR);
}
