/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:54:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 01:17:24 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player_position(t_game *game, t_player *player)
{
	if (game->map->player_direction == 'N')
	{
		player->x_direction = -1;
			// jogador olhando para cima em x e não se move em y
		player->plane_y = -0.66;
	}
	else if (game->map->player_direction == 'S')
	{
		player->x_direction = 1;
			// jogador olhando para baixo em x e não se move em y
		player->plane_y = 0.66;
	}
	else if (game->map->player_direction == 'E') // leste
	{
		player->y_direction = 1;
			// jogador olhando para o leste em y e não se move em x
		player->plane_x = -0.66;
	}
	else if (game->map->player_direction == 'W') // oeste
	{
		player->y_direction = -1;
			// jogador olhando para o oeste em y e não se move em x
		player->plane_x = 0.66;
	}
}

void	update_player_position(t_game *game)
{
	if (game->keys[LEFT_INDEX])
		rotate_player_to_left(game->player);
	if (game->keys[RIGHT_INDEX])
		rotate_player_to_right(game->player);
	if (game->keys[W_INDEX])
		move_player_forward(game, game->player);
	if (game->keys[S_INDEX])
		move_player_backward(game, game->player);
	if (game->keys[A_INDEX])
		move_player_to_left(game, game->player);
	if (game->keys[D_INDEX])
		move_player_to_right(game, game->player);
}
