/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/10 23:32:10 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	game_loop(t_game *game);

/*

If	mlx_init(void) fails to set up the connection to the graphical system,
it will return NULL, otherwise a non-null pointer is returned as a connection
identifier.

*/

int	init_game_struct(t_game *game, t_map *map, t_player *player)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	my_bzero(image, sizeof(t_image));
	game->mlx = mlx_init();
	game->w_height = W_HEIGHT;
	game->w_width = W_WIDTH;
	if (game->mlx == NULL)
	{
		my_printf_error(RED "Error. Something went wrong with "
			"mlx initialization\n" RESET);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	game->win = mlx_new_window(game->mlx, game->w_width, game->w_height,
		"Cub3d");
	game->map = map;
	game->image = image;
	game->player = player;
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
	mlx_hook(game->win, 2, 1L << 0, press_key, game);     // Evento keypress
	mlx_hook(game->win, 3, 1L << 1, release_key, game);   // Evento keyrelease
	mlx_hook(game->win, 17, 0, exit_game, game);          // Evento de fechar a janela
}

static void	game_loop(t_game *game)
{
	while (42)
	{
		usleep(937500);
		set_hooks(game);
		print_game(game);
		mlx_loop(game->mlx);
	}
}

int	start_game(t_game *game, t_map *map, t_player *player)
{
	init_game_struct(game, map, player);
	init_player_struct(map, player);
	//printf("Em start_game, antes de chamar a create_texture_imgs\n");
	//print_add_img(map->textures);
	create_texture_imgs(map->textures, game);
	game_loop(game);
	return (NO_ERROR);
}


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
}