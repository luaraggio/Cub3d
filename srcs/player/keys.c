/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:17:06 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 01:17:49 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	reset_key_array(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_KEYS)
	{
		game->keys[i] = false;
		i++;
	}
}

int	release_key(int keycode, t_game *game)
{
	//printf("Entrou na release_key\n");
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
	//raycasting(game, game->ray);
	return (NO_ERROR);
}

int	press_key(int keycode, t_game *game)
{
	//printf("Entrou na press_key\n");
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == RIGHT_KEY)
		game->keys[RIGHT_INDEX] = true;
	else if (keycode == LEFT_KEY)
		game->keys[LEFT_INDEX] = true;
	else if (keycode == W_KEY)
		game->keys[W_INDEX] = true;
	else if (keycode == S_KEY)
		game->keys[S_INDEX] = true;
	else if (keycode == A_KEY)
		game->keys[A_INDEX] = true;
	else if (keycode == D_KEY)
		game->keys[D_INDEX] = true;
	update_player_position(game);
	//raycasting(game, game->ray);
	return (NO_ERROR);
}
