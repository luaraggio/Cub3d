/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/21 15:00:30 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//static void print_player_test(t_game *game, t_player *player);

void	move_player_forward(t_game *game, t_player *player)
{
	player->x += player->x_direction * player->move_speed;
	player->y += player->y_direction * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
//	print_player_test(game, player);
}

void	move_player_backward(t_game *game, t_player *player)
{
	player->x -= player->x_direction * player->move_speed;
	player->y -= player->y_direction * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
//	print_player_test(game, player);
}
/*
static void print_player_test(t_game *game, t_player *player)
{
	printf("player->x = %f\n", player->x);
	printf("player->y = %f\n", player->y);
	printf("game->map->player_j (x) = %d\n", game->map->player_j);
	printf("game->map->player_i (y) = %d\n", game->map->player_i);
}
*/
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
	player->y_direction = old_x * sin(-ROTATION_SPEED) + player->y_direction
		* cos(-ROTATION_SPEED);
	// rotate camera (plane)
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y
		* sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y
		* cos(-ROTATION_SPEED);
}
