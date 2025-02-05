/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:17:06 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/05 02:45:02 by lraggio          ###   ########.fr       */
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

/*void handle_events(int event_type, int keycode, t_game *game) {
	if (event_type == KEY_PRESS)
		press_key(keycode, game);
	else if (event_type == KEY_RELEASE)
		release_key(keycode, game);
}

void	handle_shift(t_player *player)
{
	player->speed = MOVE_SPEED * 2;
	print_key("SHIFT", PINK);
}*/

int	press_key(int keycode, t_game *game) //t_player *player)
{
	if (keycode == ESC_KEY)
	{
		print_key("ESQ", PINK);
		exit_game(game);
	}
	if (keycode == UP_KEY)
	{
		print_key("seta para cima", PINK);
	}
	else if (keycode == DOWN_KEY)
	{

		print_key("seta para baixo", PINK);
	}
	else if (keycode == RIGHT_KEY)
	{

		print_key("seta para a direita", PINK);
	}
	else if (keycode == LEFT_KEY)
	{

		print_key("seta para a esquerda", PINK);
	}
	else if (keycode == W_KEY)
	{

		print_key("W", PINK);
	}
	else if (keycode == A_KEY)
	{

		print_key("A", PINK);
	}
	else if (keycode == S_KEY)
	{

		print_key("S", PINK);
	}
	else if (keycode == D_KEY)
	{

		print_key("D", PINK);
	}
		/*if (keycode == SHIFT_LEFT_KEY || SHIFT_RIGHT_KEY)
	{
		print_key("SHIFT", PINK);
		handle_shift(player);
	}*/
	else
		printf(RED "Alguma outra tecla foi pressionada.\n" RESET);
	//keycode = game->last_key;
	return (NO_ERROR);
}
