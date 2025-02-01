/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:54:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/01 16:54:57 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_player_struct(t_player *player)
{
	player->x_player = 0;
	player->y_player = 0;
	player->x_direction = 0;
	player->y_direction = 0;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	return (NO_ERROR);
}
