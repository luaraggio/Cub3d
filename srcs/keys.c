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

void	print_pressed_key(const char *key_name, const char *color)
{
	printf("A tecla " "%s%s" RESET " foi pressionada.\n", color, key_name);
}

/*void	print_released_key(const char *key_name, const char *color)
{
	printf("A tecla " "%s%s" RESET " foi solta.\n", color, key_name);
}*/

/*void	handle_shift(t_player *player)
{
	player->speed = MOVE_SPEED * 2;
	print_pressed_key("SHIFT", PINK);
}*/

void	reset_key_array(t_game *game)
{
	int	i;

	i = 0;
	while(i < TOTAL_KEYS)
	{
		game->keys[i] = false;
		i++;
	}

}

int	release_key(int keycode, t_game *game)
{
	if (keycode == RIGHT_KEY)
		game->keys[RIGHT_INDEX] = false;
	else if (keycode == LEFT_KEY)
		game->keys[LEFT_INDEX] = false;
	else if (keycode == W_KEY)
		game->keys[W_INDEX] = false;
	else if (keycode == S_KEY)
		game->keys[S_INDEX] = false;
	else if (keycode == A_KEY)
		game->keys[A_INDEX] = false;
	else if (keycode == D_KEY)
		game->keys[D_INDEX] = false;
	update_player_position(game);
	return (NO_ERROR);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == RIGHT_KEY)
	{
		game->keys[RIGHT_INDEX] = true;
		print_pressed_key("seta para a direita", PINK);
	}
	else if (keycode == LEFT_KEY)
	{
		game->keys[LEFT_INDEX] = true;
		print_pressed_key("seta para a esquerda", PINK);
	}
	else if (keycode == W_KEY)
	{
		game->keys[W_INDEX] = true;
		print_pressed_key("W", PINK);
	}
	else if (keycode == S_KEY)
	{
		game->keys[S_INDEX] = true;
		print_pressed_key("S", PINK);
	}
	else if (keycode == A_KEY)
	{
		game->keys[A_INDEX] = true;
		print_pressed_key("A", PINK);
	}
	else if (keycode == D_KEY)
	{
		game->keys[D_INDEX] = true;
		print_pressed_key("D", PINK);
	}
	// Raycasting:
	update_player_position(game);
	return (NO_ERROR);
}
