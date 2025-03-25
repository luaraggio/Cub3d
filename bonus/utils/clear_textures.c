/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:21:48 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/25 13:05:20 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	if (map->textures->fd_north_texture != -1)
		close(map->textures->fd_north_texture);
	if (map->textures->fd_south_texture != -1)
		close(map->textures->fd_south_texture);
	if (map->textures->fd_west_texture != -1)
		close(map->textures->fd_west_texture);
	if (map->textures->fd_east_texture != -1)
		close(map->textures->fd_east_texture);
}

void	destroy_texture_imgs(t_game *game, t_textures *textures)
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
	free_imgs(textures);
}

void	free_imgs(t_textures *textures)
{
	if (textures->north_texture_img)
	{
		free(textures->north_texture_img);
		textures->north_texture_img = NULL;
	}
	if (textures->south_texture_img)
	{
		free(textures->south_texture_img);
		textures->south_texture_img = NULL;
	}
	if (textures->west_texture_img)
	{
		free(textures->west_texture_img);
		textures->west_texture_img = NULL;
	}
	if (textures->east_texture_img)
	{
		free(textures->east_texture_img);
		textures->east_texture_img = NULL;
	}
}
