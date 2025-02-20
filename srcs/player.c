/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:54:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/10 22:22:19 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_player_position(t_game *game, t_player *player)
{
	if (game->map->player_direction == 'N')
	{
		player->x_direction = -1; //jogador olhando para cima em x e não se move em y
		player->plane_y = -0.66;
	}
	else if (game->map->player_direction == 'S')
	{
		player->x_direction = 1; //jogador olhando para baixo em x e não se move em y
		player->plane_y = 0.66;
	}
	else if (game->map->player_direction == 'E') //leste
	{
		player->y_direction = 1; //jogador olhando para o leste em y e não se move em x
		player->plane_x = -0.66;
	}
	else if (game->map->player_direction == 'W') //oeste
	{
		player->y_direction = -1; //jogador olhando para o oeste em y e não se move em x
		player->plane_x = 0.66;
	}
}

int	init_player(t_game *game, t_player *player)
{
	game->player = player;
	player->x = game->map->player_j;
	player->y = game->map->player_i;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	set_player_position(game, player);
	return (NO_ERROR);
}
