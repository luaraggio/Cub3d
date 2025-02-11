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

/*
Obs: set_player_position

-> as direções que não inicializei com 0 é porque já estão como 0 na função init_player_struct
*/

void	set_player_position(t_map *map, t_player *player)
{
	if (map->player_direction == 'N')
	{
		player->x_direction = -1; //jogador olhando para cima em x e não se move em y
		player->plane_y = -0.66;
	}
	else if (map->player_direction == 'S')
	{
		player->x_direction = 1; //jogador olhando para baixo em x e não se move em y
		player->plane_y = 0.66;
	}
	else if (map->player_direction == 'E') //leste
	{
		player->y_direction = 1; //jogador olhando para o leste em y e não se move em x
		player->plane_x = -0.66;
	}
	else if (map->player_direction == 'W') //oeste
	{
		player->y_direction = -1; //jogador olhando para o oeste em y e não se move em x
		player->plane_x = 0.66;
	}
}

int	init_player_struct(t_map *map, t_player *player)
{
	//my_bzero(player, sizeof(player));
	player->x = map->player_j;
	player->y = map->player_i;
	player->plane_x = 0;
	player->plane_y = 0;
	player->x_direction = 0;
	player->y_direction = 0;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	set_player_position(map, player);
	return (NO_ERROR);
}
