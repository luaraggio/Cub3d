/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/21 14:05:38 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_raycasting_struct(t_game *game)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (ERROR);
	ray->pos_x = game->player->x;
	ray->pos_y = game->player->y;
	ray->dir_x = game->player->x_direction;
	ray->dir_y = game->player->y_direction;
	game->ray = ray;
	return (NO_ERROR);
}

void	render_game(t_game *game)
{
	init_raycasting_struct(game);
}