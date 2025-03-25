/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:03:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/25 13:04:29 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	rotate_player_to_right(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	player->x_direction = player->x_direction * cos(ROTATION_SPEED)
		- player->y_direction * sin(ROTATION_SPEED);
	player->y_direction = old_x * sin(ROTATION_SPEED) + player->y_direction
		* cos(ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(ROTATION_SPEED) - player->plane_y
		* sin(ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(ROTATION_SPEED) + player->plane_y
		* cos(ROTATION_SPEED);
}

void	rotate_player_to_left(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	player->x_direction = old_x * cos(-ROTATION_SPEED) - player->y_direction
		* sin(-ROTATION_SPEED);
	player->y_direction = old_x * sin(-ROTATION_SPEED) + player->y_direction
		* cos(-ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y
		* sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y
		* cos(-ROTATION_SPEED);
}
