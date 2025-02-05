/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/05 03:08:30 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*

If	mlx_init(void) fails to set up the connection to the graphical system,
it will return NULL, otherwise a non-null pointer is returned as a connection
identifier.

*/

int	init_game_struct(t_game *game, t_map *map)
{
	game->w_height = W_HEIGHT;
	game->w_width = W_WIDTH;
	game->map = map;
	return (NO_ERROR);
}

int	exit_game(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clear_map(game->map);
	exit(EXIT_SUCCESS);
	return (NO_ERROR);
}

int	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, press_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	return (NO_ERROR);
}

int	start_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		my_printf_error(RED "Error. Something went wrong with "
			"mlx initialization\n" RESET);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	init_game_struct(game, map);
	game->win = mlx_new_window(game->mlx, game->w_width, game->w_height,
			"Cub3d");
	set_hooks(game);
	mlx_loop(game->mlx);
	return (NO_ERROR);
}
