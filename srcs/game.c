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

/*

If	mlx_init(void) fails to set up the connection to the graphical system,
it will return NULL, otherwise a non-null pointer is returned as a connection
identifier.

*/

int	init_game_struct(t_game *game, t_map *map)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	my_bzero(image, sizeof(t_image));
	game->mlx = mlx_init();
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
	game->w_height = W_HEIGHT;
	game->w_width = W_WIDTH;
	game->map = map;
	game->image = image;
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

int	start_game(t_game *game, t_map *map, t_player *player)
{
	init_game_struct(game, map);
	set_hooks(game);
	init_player_struct(map, player);
	print_game(game, map);
	//draw_player(game, player);
	mlx_loop(game->mlx);
	return (NO_ERROR);
}
