/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/25 13:05:23 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	clear_all(t_game *game, t_map *map)
{
	destroy_texture_imgs(game, map->textures);
	clear_map(map);
	clear_game(game);
}

void	clear_map(t_map *map)
{
	my_clean_vect(map->map_file);
	map->map_file = NULL;
	if (map->map)
	{
		my_clean_vect(map->map);
		map->map = NULL;
		if (map->map_int)
		{
			my_clean_int_vect(map->map_int);
			map->map_int = NULL;
		}
	}
	if (map->textures)
	{
		clear_texture_map(map);
		free(map->textures);
		map->textures = NULL;
	}
}

void	clear_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image->img);
	free(game->image);
	game->image = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
	free(game->ray);
	game->ray = NULL;
}
