/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/25 13:10:37 by lpaixao-         ###   ########.fr       */
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
	my_clean_vect(map->map);
	free(map->north_texture);
	free(map->south_texture);
	free(map->west_texture);
	free(map->east_texture);
	close_texture_fds(map);
}

void	close_texture_fds(t_map *map)
{
	close(map->fd_north_texture);
	close(map->fd_south_texture);
	close(map->fd_west_texture);
	close(map->fd_east_texture);
}

void	clear_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image->img);
	free(game->image);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}