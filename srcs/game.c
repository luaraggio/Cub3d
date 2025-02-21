/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/12 15:03:18 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		my_printf_error(RED "Error. Something went wrong with "
			"mlx initialization\n" RESET);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			return (ERROR);
	}
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT,
		"Cub3d");
	reset_key_array(game);
	init_player(game, player);
	return (NO_ERROR);
}

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
//	printf("game->player->x_direction = %f\n", game->player->x_direction);
//	printf("game->player->y_direction = %f\n", game->player->y_direction);
	print_game(game);
	//update_player_position(game);
	usleep(937500);
	return (0);
}

void	create_general_img(void *mlx, t_image *img)
{
	img->size_line = W_WIDTH;
	img->size_height = W_HEIGHT;
	img->img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_line), &(img->endian));
}

void	play_cub3d(t_game *game, t_map *map, t_player *player)
{
	init_game(game, map, player);
	create_texture_imgs(map->textures, game);
	create_general_img(game->mlx, game->image);
	set_hooks(game);
}

/*
void	print_add_img(t_textures *textures)
{
	printf("& t_image de north: %p\n", textures->north_texture_img);
	printf("textures->north_texture_img->img: %p\n", textures->north_texture_img->img);
	printf("& t_image de south: %p\n", textures->south_texture_img);
	printf("textures->south_texture_img->img: %p\n", textures->south_texture_img->img);
	printf("& t_image de west: %p\n", textures->west_texture_img);
	printf("textures->west_texture_img->img: %p\n", textures->west_texture_img->img);
	printf("& t_image de east: %p\n", textures->east_texture_img);
	printf("textures->east_texture_img->img: %p\n", textures->east_texture_img->img);
}*/