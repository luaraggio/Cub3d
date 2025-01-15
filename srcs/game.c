/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/15 20:09:24 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*

If mlx_init() fails to set up the connection to the graphical system, it will return NULL,
otherwise a non-null pointer is returned as a connection identifier.

*/

int init_game_struct(t_game *game)
{
    game->w_height = W_HEIGHT;
    game->w_width = W_WIDTH;
	game->moves = 0;
    return (NO_ERROR);
}

int exit_game(t_game *game)
{
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(EXIT_SUCCESS);
    return (NO_ERROR);
}

int start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
    {
        my_printf_error(RED "Error. Something went wrong with image initialization\n" RESET);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (ERROR);
    }
    init_game_struct(game);
    game->win = mlx_new_window(game->mlx, game->w_width, game->w_height, "Cub3d");
    return (NO_ERROR);
}
