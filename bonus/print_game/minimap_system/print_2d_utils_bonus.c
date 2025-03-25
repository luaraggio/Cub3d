/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:37:08 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/25 11:21:26 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d_bonus.h"

void	found_wall(t_game *game, t_map2d *map_2d, int i, int j)
{
	int	dy;
	int	dx;
	int	x;
	int	y;

	dy = 0;
	dx = 0;
	x = j * map_2d->scale;
	y = i * map_2d->scale;
	while (dy < map_2d->scale)
	{
		dx = 0;
		while (dx < map_2d->scale)
		{
			my_mlx_pixel_put(game->image, x + dx, y + dy, map_2d->wall_color);
			dx++;
		}
		dy++;
	}
}

int	get_opposite_color(int color)
{
	int	r;
	int	g;
	int	b;
	int	new_color;

	r = 0xFF - ((color >> 16) & 0xFF);
	g = 0xFF - ((color >> 8) & 0xFF);
	b = 0xFF - (color & 0xFF);
	new_color = (r << 16) | (g << 8) | b;
	return (new_color);
}

void	draw_player(t_game *game, t_map2d *map2d)
{
	int		size;
	int		i;
	int		j;
	float	player_x;
	float	player_y;

	player_x = game->player->x + 0.5;
	player_y = game->player->y + 0.5;
	size = 5;
	i = -size;
	while (i <= size)
	{
		j = -size;
		while (j <= size)
		{
			my_mlx_pixel_put(game->image, (int)(player_x * map2d->scale) + j,
				(int)(player_y * map2d->scale) + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_line_to_wall(t_game *game, t_map2d *map2d)
{
	double	x;
	double	y;
	double	x_dir;
	double	y_dir;

	x = (game->player->x + 0.5) * map2d->scale;
	y = (game->player->y + 0.5) * map2d->scale;
	x_dir = game->player->x_direction * map2d->scale;
	y_dir = game->player->y_direction * map2d->scale;
	while (map2d->map_2d[(int)(y / map2d->scale)][(int)(x
			/ map2d->scale)] != '1')
	{
		my_mlx_pixel_put(game->image, (int)x, (int)y, 0xFFFFFF);
		x += x_dir * 0.1;
		y += y_dir * 0.1;
	}
}
