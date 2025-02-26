/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 17:18:14 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exit_game(t_game *game)
{
	clear_all(game, game->map);
	exit(EXIT_SUCCESS);
	return (NO_ERROR);
}

void	set_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 3, 1L << 1, release_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}

int	game_loop(t_game *game)
{
	print_game(game);
	usleep(937500);
	return (0);
}

void	play_cub3d(t_game *game, t_map *map, t_player *player)
{
	init_game(game, map, player);
	create_texture_imgs(map->textures, game);
	create_general_img(game->mlx, game->image);
	raycasting(game, game->ray);
	set_hooks(game);
}

/*
void	print_add_img(t_textures *textures)
{
	printf("& t_image de north: %p\n", textures->north_texture_img);
	printf("textures->north_texture_img->img: %p\n",
		textures->north_texture_img->img);
	printf("& t_image de south: %p\n", textures->south_texture_img);
	printf("textures->south_texture_img->img: %p\n",
		textures->south_texture_img->img);
	printf("& t_image de west: %p\n", textures->west_texture_img);
	printf("textures->west_texture_img->img: %p\n",
		textures->west_texture_img->img);
	printf("& t_image de east: %p\n", textures->east_texture_img);
	printf("textures->east_texture_img->img: %p\n",
		textures->east_texture_img->img);
}*/
