/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 00:25:49 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_player_forward(t_game *game, t_player *player)
{
	if (game->map->map_int[(int)(player->x + player->x_direction
			* player->move_speed)][(int)(player->y)] == 0)
		player->x += player->x_direction * player->move_speed;
	if (game->map->map_int[(int)(player->x)][(int)(player->y
			+ player->y_direction * player->move_speed)] == 0)
		player->y += player->y_direction * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
}

void	move_player_backward(t_game *game, t_player *player)
{
	if (game->map->map_int[(int)(player->x - player->x_direction
			* player->move_speed)][(int)(player->y)] == 0)
		player->x -= player->x_direction * player->move_speed;
	if (game->map->map_int[(int)(player->x)][(int)(player->y
			- player->y_direction * player->move_speed)] == 0)
		player->y -= player->y_direction * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
}

void	move_player_to_left(t_game *game, t_player *player)
{
	if (game->map->map_int[(int)(player->x + player->plane_x
			* player->move_speed)][(int)(player->y)] == 0)
		player->x += player->plane_x * player->move_speed;
	if (game->map->map_int[(int)(player->x)][(int)(player->y +
			player->plane_y * player->move_speed)] == 0)
		player->y += player->plane_y * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
}

void	move_player_to_right(t_game *game, t_player *player)
{
	if (game->map->map_int[(int)(player->x - player->plane_x
			* player->move_speed)][(int)(player->y)] == 0)
		player->x -= player->plane_x * player->move_speed;
	if (game->map->map_int[(int)(player->x)][(int)(player->y -
			player->plane_y * player->move_speed)] == 0)
		player->y -= player->plane_y * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
}

void	rotate_player_to_left(t_player *player)
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

void	rotate_player_to_right(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	// rotate player
	player->x_direction = old_x * cos(-ROTATION_SPEED) - player->y_direction
		* sin(-ROTATION_SPEED);
	player->y_direction = old_x * sin(-ROTATION_SPEED) + player->y_direction
		* cos(-ROTATION_SPEED);
	// rotate camera (plane)
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y
		* sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y
		* cos(-ROTATION_SPEED);
}
