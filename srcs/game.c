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

/*

If	mlx_init(void) fails to set up the connection to the graphical system,
it will return NULL, otherwise a non-null pointer is returned as a connection
identifier.

*/

void	init_image_struct(t_game *game, t_map *map)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	my_bzero(image, sizeof(t_image));
	game->map = map;
	game->image = image;
}

t_game	*init_game(t_game *game, t_map *map, t_player *player)
{
	int	i;

	// t_game	*game;
	i = -1;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), NULL);
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3d");
	if (!game->win)
		return (free(game), NULL);
	game->keys = malloc(sizeof(int) * MAX_KEYS);
	if (!game->keys)
	{
		mlx_destroy_window(game->mlx, game->win);
		return (free(game), NULL);
	}
	while (++i < MAX_KEYS)
		game->keys[i] = 0;
	init_image_struct(game, map);
	init_player_struct(map, player);
	return (game);
}

int	exit_game(t_game *game)
{
	clear_all(game, game->map);
	exit(EXIT_SUCCESS);
	return (NO_ERROR);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 3, 1L << 1, release_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}

int	play_cub3d(t_game *game, t_map *map, t_player *player)
{
	init_game(game, map, player);
	set_hooks(game);
	print_game(game, map);
	// draw_player(game, player);
	mlx_loop(game->mlx);
	return (NO_ERROR);
}
