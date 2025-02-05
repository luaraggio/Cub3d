/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/05 03:12:32 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
  Rotate functions - Aplicam a rotação no vetor de direção direita ou
  esquerda.
*/

void	move_player_forward(t_player *player)
{
	player->x += player->x_direction * player->move_speed;
	player->y += player->y_direction * player->move_speed;
}

void	move_player_backward(t_player *player)
{
	player->x -= player->x_direction * player->move_speed;
	player->y -= player->y_direction * player->move_speed;
}


void	turn_player_to_left(t_player *player)
{
    double  old_x_direction;     // Old/initial player direction in x
    double  old_plane_x;

	old_x_direction = player->x_direction;
    old_plane_x = 0;

    // Aplica a rotação no vetor de direção
    player->x_direction = player->x_direction * cos(-player->rotation_speed)
		- player->y_direction * sin(-player->rotation_speed);
	player->y_direction = old_x_direction * sin(-player->rotation_speed)
		+ player->y_direction * cos(-player->rotation_speed);

	// Rotação do plano da câmera (para perspectiva correta)
    old_plane_x = player->plane_x;

	player->plane_x = player->plane_x * cos(-player->rotation_speed)
		- player->plane_y * sin(-player->rotation_speed);
	player->plane_y = old_plane_x * sin(-player->rotation_speed)
		+ player->plane_y * cos(-player->rotation_speed);
}

void	turn_player_to_right(t_player *player)
{
	double	old_x_direction;
    double  old_plane_x;

    old_x_direction = player->x_direction;
    old_plane_x = 0;

	// Aplica a rotação no vetor de direção
	player->x_direction = player->x_direction * cos(player->rotation_speed)
		- player->y_direction * sin(player->rotation_speed);
	player->y_direction = old_x_direction * sin(player->rotation_speed)
		+ player->y_direction * cos(player->rotation_speed);

	// Rotação do plano da câmera (para perspectiva correta)
	old_plane_x = player->plane_x;

	player->plane_x = player->plane_x * cos(player->rotation_speed)
		- player->plane_y * sin(player->rotation_speed);
	player->plane_y = old_plane_x * sin(player->rotation_speed)
		+ player->plane_y * cos(player->rotation_speed);
}
