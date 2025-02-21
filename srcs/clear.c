/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/21 14:01:11 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	destroy_texture_imgs(t_game *game, t_textures *textures);

void	clear_all(t_game *game, t_map *map)
{
	destroy_texture_imgs(game, map->textures);
	clear_map(map);
	clear_game(game);
}

void	clear_map(t_map *map)
{
	my_clean_vect(map->map_file);
	my_clean_vect(map->map);
	clear_texture_map(map);
	free(map->textures);
	map->textures = NULL;
}

void	clear_texture_map(t_map *map)
{
	close_texture_fds(map);
	free(map->textures->north_texture);
	map->textures->north_texture = NULL;
	free(map->textures->south_texture);
	map->textures->south_texture = NULL;
	free(map->textures->west_texture);
	map->textures->west_texture = NULL;
	free(map->textures->east_texture);
	map->textures->east_texture = NULL;
}

void	close_texture_fds(t_map *map)
{
	close(map->textures->fd_north_texture);
	close(map->textures->fd_south_texture);
	close(map->textures->fd_west_texture);
	close(map->textures->fd_east_texture);
}

static void	destroy_texture_imgs(t_game *game, t_textures *textures)
{
	if (textures->north_texture_img && textures->north_texture_img->img)
	{
		mlx_destroy_image(game->mlx, textures->north_texture_img->img);
		textures->north_texture_img->img = NULL;
	}
	if (textures->south_texture_img && textures->south_texture_img->img)
	{
		mlx_destroy_image(game->mlx, textures->south_texture_img->img);
		textures->south_texture_img->img = NULL;
	}
	if (textures->west_texture_img && textures->west_texture_img->img)
	{
		mlx_destroy_image(game->mlx, textures->west_texture_img->img);
		textures->west_texture_img->img = NULL;
	}
	if (textures->east_texture_img && textures->east_texture_img->img)
	{
		mlx_destroy_image(game->mlx, textures->east_texture_img->img);
		textures->east_texture_img->img = NULL;
	}
	free(textures->north_texture_img);
	textures->north_texture_img = NULL;
	free(textures->south_texture_img);
	textures->south_texture_img = NULL;
	free(textures->west_texture_img);
	textures->west_texture_img = NULL;
	free(textures->east_texture_img);
	textures->east_texture_img = NULL;
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
