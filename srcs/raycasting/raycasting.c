/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 20:03:46 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_vertical_lines(t_game *game, t_raycast *ray, int x)
{
	int	y;
	int	color;

	color = 0xFF0000;
	/* Vermelho */
	printf("Draw start: %i\n", ray->draw_start);
	printf("Draw end: %i\n", ray->draw_end);
	y = ray->draw_start;
	if (ray->side == VERTICAL_SIDE)
		color = (color >> 1) & 8355711;
	/* Se o raio atingiu uma borda vertical, escurece a cor */
	while (y < ray->draw_end)
	{
		my_mlx_pixel_put(game->image->img, x, y, color);
		y++;
	}
}

void	set_ray_values(t_game *game, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)W_WIDTH - 1;
		ray->dir_x = game->player->x_direction + game->player->plane_x
			* ray->camera_x; // calcula direção x do raio
		ray->dir_y = game->player->y_direction + game->player->plane_y
			* ray->camera_x; // calcula direção y do raio
			// o quanto o raio tem que andar naquela direção antes de cruzar uma linha do grid.
		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);
}

void	raycasting(t_game *game, t_raycast *ray)
{
	printf("Oi da funcao de raycasting\n");
	int	x;

	x = 0;
	while (x < W_WIDTH)
	 /* Lança um raio para cada coluna da tela, da esquerda pra direita*/
	{
		printf("Oi de dentro do loop do raycasting!!\n");
		ray->hit = 0;
		ray->map_x = (int)game->player->x;
		ray->map_y = (int)game->player->y;
		set_ray_values(game, ray, x);
		calculate_ray_direction(game, ray);
		perform_dda(game, ray);
		calculate_wall_distance(game, ray);
		calculate_wall_height(ray);
		draw_vertical_lines(game, ray, x);
		x++;
	}
}
