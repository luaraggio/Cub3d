/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:54:55 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/05 03:08:46 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_player_struct(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->x_direction = -1;
	player->y_direction = -1;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	return (NO_ERROR);
}

void	draw_player(t_game *game, t_player *player)
{
	//Colocando o jogador no meio do mapa
	player->x = 2 * TILE_SIZE + TILE_SIZE/2;
	player->y = 2 * TILE_SIZE + TILE_SIZE/2;

	int	i;
	int	j;
	int	radius;

	i = -TILE_SIZE/4;
	j = 0;
	radius = TILE_SIZE/4;
	while (i <= radius)
	{
		j = -radius;
		while (j <= radius)
		{
			if (i * i + j * j <= radius * radius)
				mlx_pixel_put(game->mlx, game->win, player->x + i,
			player->y + j, 0x00FF0000);
			j++;
		}
		i++;
	}
}