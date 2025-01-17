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

int press_key(int keycode, t_game *game)
{
    if (keycode == ESC_KEY)
    {
        printf("A tecla " PINK"ESQ"RESET " foi pressionada.\n");
        exit_game(game);
    }
    if (keycode == UP_KEY)
        printf("A tecla " PINK"seta para cima"RESET " foi pressionada.\n");
    if (keycode == DOWN_KEY)
        printf("A tecla " PINK"seta para baixo"RESET " foi pressionada.\n");
    if (keycode == RIGHT_KEY)
        printf("A tecla " PINK"seta para a direita"RESET " foi pressionada.\n");
    if (keycode == LEFT_KEY)
        printf("A tecla " PINK"seta para a esquerda"RESET " foi pressionada.\n");
    if (keycode == W_KEY)
        printf("A tecla " PINK"W"RESET " foi pressionada.\n");
    if (keycode == A_KEY)
        printf("A tecla " PINK"A"RESET " foi pressionada.\n");
    if (keycode == S_KEY)
        printf("A tecla " PINK"S"RESET " foi pressionada.\n");
    if (keycode == D_KEY)
        printf("A tecla " PINK"D"RESET " foi pressionada.\n");
    else
        printf(RED"Alguma outra tecla foi pressionada.\n"RESET);
    return (NO_ERROR); 
}

int exit_game(t_game *game)
{
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(EXIT_SUCCESS);
    return (NO_ERROR);
}

int set_hooks(t_game *game)
{
    mlx_key_hook(game->win, press_key, game);
    mlx_hook(game->win, 17, 0, exit_game, game);
    return (NO_ERROR);
}

int start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (game->mlx == NULL)
    {
        my_printf_error(RED "Error. Something went wrong with mlx initialization\n" RESET);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (ERROR);
    }
    init_game_struct(game);
    game->win = mlx_new_window(game->mlx, game->w_width, game->w_height, "Cub3d");
    set_hooks(game);
    mlx_loop(game->mlx);
    return (NO_ERROR);
}
