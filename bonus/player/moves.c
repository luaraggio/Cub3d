/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/25 13:04:23 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	is_valid_move(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_y >= W_HEIGHT || map_x >= W_WIDTH)
		return (0);
	return (game->map->map_int[map_y][map_x] == 0);
}

void	move_player_forward(t_game *game, t_player *player)
{
	if (is_valid_move(game, player->x + player->x_direction
			* player->move_speed, player->y))
		player->x += player->x_direction * player->move_speed;
	if (is_valid_move(game, player->x, player->y + player->y_direction
			* player->move_speed))
		player->y += player->y_direction * player->move_speed;
	game->map->player_i = (int)player->y;
	game->map->player_j = (int)player->x;
}

void	move_player_backward(t_game *game, t_player *player)
{
	if (is_valid_move(game, player->x - player->x_direction
			* player->move_speed, player->y))
		player->x -= player->x_direction * player->move_speed;
	if (is_valid_move(game, player->x, player->y - player->y_direction
			* player->move_speed))
		player->y -= player->y_direction * player->move_speed;
	game->map->player_i = (int)player->y;
	game->map->player_j = (int)player->x;
}

void	move_player_to_right(t_game *game, t_player *player)
{
	if (is_valid_move(game, player->x + player->plane_x * player->move_speed,
			player->y))
		player->x += player->plane_x * player->move_speed;
	if (is_valid_move(game, player->x, player->y + player->plane_y
			* player->move_speed))
		player->y += player->plane_y * player->move_speed;
	game->map->player_i = (int)player->y;
	game->map->player_j = (int)player->x;
}

void	move_player_to_left(t_game *game, t_player *player)
{
	if (is_valid_move(game, player->x - player->plane_x * player->move_speed,
			player->y))
		player->x -= player->plane_x * player->move_speed;
	if (is_valid_move(game, player->x, player->y - player->plane_y
			* player->move_speed))
		player->y -= player->plane_y * player->move_speed;
	game->map->player_i = (int)player->y;
	game->map->player_j = (int)player->x;
}
