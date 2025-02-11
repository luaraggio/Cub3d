/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/10 21:36:16 by lraggio          ###   ########.fr       */
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

/*void	turn_player_to_left(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = 0;
	player->x_direction = old_x * cos(-0.1) - player->y_direction * sin(-0.1);
	player->y_direction = old_x * sin(-0.1) + player->y_direction * cos(-0.1);
}*/
