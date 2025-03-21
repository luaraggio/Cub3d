/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:26:26 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/21 15:50:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Determines the initial step direction and side distances for 
 *        raycasting.
 *
 * What does it do?
 *  - Sets the values of step_x and step_y, indicating whether the ray moves 
 *    forward (+1) or backward (-1) on the map.
 *  - Computes side_dist_x and side_dist_y, representing the distance the ray 
 *    must travel to reach the first edge of a map cell.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains 
 *             player information.
 * @param ray Pointer to the raycast structure (`t_raycast`), which contains 
 *            ray information.
 */

void	calculate_ray_direction(t_game *game, t_raycast *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player->x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player->y)
			* ray->delta_dist_y;
	}
}

/**
 * @brief A loop that increments the ray by one square at a time until it 
 *        hits a wall.
 *
 * What does it do?
 *  - Uses the previously calculated values (sideDistX and sideDistY) to 
 *    determine whether the ray advances first along the X or Y axis.
 *  - Each step in the loop moves the ray to the next map cell until it 
 *    encounters a wall.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains 
 *             player information.
 * @param ray Pointer to the raycast structure (`t_raycast`), which contains 
 *            ray information.
 */

void	perform_dda(t_game *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = VERTICAL_SIDE;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = HORIZONTAL_SIDE;
		}
		if (game->map->map_int[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
}

/**
 * @brief Calculates the perpendicular ray distance (Euclidean distance would 
 *        cause a fisheye effect!).
 *
 * What does it do?
 *  - Computes the wall height on the screen after the ray hits a wall in 
 *    the map.
 *  - Uses the perpendicular distance from the ray to the wall 
 *    (`perp_wall_dist`) to determine the size of the line that should be 
 *    drawn in the center of the screen.
 *
 * @param ray Pointer to the raycast structure (`t_raycast`), which contains 
 *            ray information.
 */

void	calculate_wall_height(t_raycast *ray)
{
	ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
}

/**
 * @brief Calculates the player's perpendicular distance to the wall and 
 *        adjusts wall sizes on the screen for correct perspective.
 *
 * What does it do?
 *  - Computes `wall_x` to determine the exact point where the ray 
 *    collided within the block.
 *  - Helps select which part of the wall texture should be used.
 *
 * @param ray Pointer to the raycast structure (`t_raycast`), which contains 
 *            ray information.
 */

void	calculate_wall_distance(t_game *game, t_raycast *ray)
{
	if (ray->side == VERTICAL_SIDE)
	{
		ray->perp_wall_dist = (ray->map_x - game->player->x + (1 - ray->step_x)
				/ 2) / ray->dir_x;
		ray->wall_x = game->player->y + ray->perp_wall_dist * ray->dir_y;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - game->player->y + (1 - ray->step_y)
				/ 2) / ray->dir_y;
		ray->wall_x = game->player->x + ray->perp_wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
}
