/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/12 15:04:50 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_forward(t_player *player)
{
	player->x += player->x_direction * player->move_speed;
	player->y += player->y_direction * player->move_speed;
}

void	move_player_backward(t_player *player)
{
	player->x -= player->x_direction * player->move_speed;
	player->y -= player->y_direction * player->move_speed;
}

void	turn_player_to_left(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	// rotate player
	player->x_direction = player->x_direction * cos(ROTATION_SPEED)
		- player->y_direction * sin(ROTATION_SPEED);
	player->y_direction = old_x * sin(ROTATION_SPEED) + player->y_direction
		* cos(ROTATION_SPEED);
	// rotate camera (plane)
	player->plane_x = player->plane_x * cos(ROTATION_SPEED) - player->plane_y
		* sin(ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(ROTATION_SPEED) + player->plane_y
		* cos(ROTATION_SPEED);
}

void	turn_player_to_right(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	// rotate player
	player->x_direction = player->x * cos(-ROTATION_SPEED) - player->y_direction
		* sin(-ROTATION_SPEED);
	player->y_direction = old_x * sin(-ROTATION_SPEED) + player->y
		* cos(-ROTATION_SPEED);
	// rotate camera (plane)
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y
		* sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y
		* cos(-ROTATION_SPEED);
}
