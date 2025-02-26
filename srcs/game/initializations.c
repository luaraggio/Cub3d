/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:59:47 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 01:30:40 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_game(t_game *game, t_map *map, t_player *player)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (ERROR);
	my_bzero(image, sizeof(t_image));
	game->map = map;
	game->image = image;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		my_printf_error(RED "Error\n Something went wrong with "
							"mlx initialization\n" RESET);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3d");
	reset_key_array(game);
	init_player(game, player);
	init_raycasting(game);
	return (NO_ERROR);
}

int	init_player(t_game *game, t_player *player)
{
	game->player = player;
	player->x = game->map->player_j;
	player->y = game->map->player_i;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	set_player_position(game, player);
	return (NO_ERROR);
}
