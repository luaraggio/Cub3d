/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:53 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/01 16:53:54 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_player *player) // frente
{
	player->x_player += player->x_coordinate * player->move_speed;
	player->y_player += player->y_coordinate * player->move_speed;
}

void	move_backward(t_player *player) // trás
{
	player->x_player -= player->x_coordinate * player->move_speed;
	player->y_player -= player->y_coordinate * player->move_speed;
}

void	turn_right(t_player *player) // direita
{
	player->x_player = player->x_coordinate * player->move_speed;
	player->y_player = player->y_coordinate * player->move_speed;
}

void	turn_left(t_player *player, double angle) // esquerda
{
	player->x_direction = (player->x_direction * cos(angle)) - (player->y_direction * sin(angle));
}
