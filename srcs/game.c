/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:24:23 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/14 23:29:03 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*int close_game(t_game *game)
{
    mlx_destroy_display(game->mlx);
    exit(EXIT_SUCCESS);
    return (END);
}*/

/*

If mlx_init() fails to set up the connection to the graphical system, it will return NULL,
otherwise a non-null pointer is returned as a connection identifier.

*/

int init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
    {
        my_printf_error(RED "Error. Something went wrong with image initialization\n" RESET);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (ERROR);
    }
    return (NO_ERROR);
}

int init_game_struct(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->w_height = W_HEIGHT * 100;
    game->w_width = W_WIDTH * 100;
	//game->moves = 0;
    return (NO_ERROR);
}

int start_game(t_game *game)
{
    init_game_struct(game);
    init_mlx(game);
    game->win = mlx_new_window(game->mlx, game->w_width, game->w_height, "Cub3d 🤖");
    return (NO_ERROR);
}
