/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/18 18:51:15 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	if (game->map->map_int[(int)(player->x)][(int)(player->y - player->plane_y
			* player->move_speed)] == 0)
		player->y -= player->plane_y * player->move_speed;
	if (game->map->map_int[(int)(player->x - player->plane_x
			* player->move_speed)][(int)(player->y)] == 0)
		player->x -= player->plane_x * player->move_speed;
	game->map->player_j = (int)player->x;
	game->map->player_i = (int)player->y;
}
