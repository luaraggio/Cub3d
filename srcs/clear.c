/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/05 15:32:45 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_all(t_game *game, t_map *map)
{
	clear_game(game);
	clear_map(map);
}

void	clear_map(t_map *map)
{
	my_clean_vect(map->map_file);
	my_clean_vect(map->map);
	free(map->textures->north_texture);
	free(map->textures->south_texture);
	free(map->textures->west_texture);
	free(map->textures->east_texture);
	close_texture_fds(map);
	free(map->textures);
}

void	close_texture_fds(t_map *map)
{
	close(map->textures->fd_north_texture);
	close(map->textures->fd_south_texture);
	close(map->textures->fd_west_texture);
	close(map->textures->fd_east_texture);
}


void	clear_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image->img);
	free(game->image);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
