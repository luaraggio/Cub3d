/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:54:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/10 21:35:38 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_player_struct(t_map *map, t_player *player)
{
	my_bzero(player, sizeof(player));
	player->x = -1;
	player->y = -1;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	//set_player_position(map, player);
	return (NO_ERROR);
}
