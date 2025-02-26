/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 00:14:18 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*void	draw_vertical_lines(t_game *game, t_raycast *ray)
{
	double	step;
	double	texture_position;
	unsigned int	color;
	int	y;
	int	texture_y;

	y = ray->draw_start;
	step = 1.0 * TEXTURE_SIZE / ray->line_height; // How much to increase the texture coordinate per screen pixel
	texture_position = (ray->draw_start - W_HEIGHT / 2 + ray->line_height / 2) * step; // Starting texture coordinate
		while (y < ray->draw_end)
		{
			texture_y = (int)texture)position & (TEXTURE_SIZE - 1);
			texture_position += step;
			y++;
		}
	for(int y = drawStart; y<drawEnd; y++)
	{
	  // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
	  int texY = (int)texPos & (texHeight - 1);
	  texPos += step;
	  Uint32 color = texture[texNum][texHeight * texY + texX];
	  //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
	  if(side == 1) color = (color >> 1) & 8355711;
	  buffer[y][x] = color;
	}//
  }
}*/

void	draw_vertical_lines(t_game *game, t_raycast *ray, int x)
{
	int y;
	int color; // Define a cor base (pode vir de uma textura ou ser fixa)

	color = 0xFF0000; // Vermelho
	y = ray->draw_start;
	if (ray->side == VERTICAL_SIDE)
		color = (color >> 1) & 8355711; // Se o raio atingiu uma borda vertical, escurece a cor
	while (y < ray->draw_end)
	{
		my_mlx_pixel_put(game->image->img, x, y, color);
		y++;
	}
}

void raycasting(t_game *game, t_raycast *ray)
{
    int x;

    x = 0;
    while (x < W_WIDTH)  // lança um raio para cada coluna da tela, da esquerda pra direita
    {
        ray->camera_x = 2 * x / (double)W_WIDTH - 1;
        ray->dir_x = game->player->x_direction + game->player->plane_x * ray->camera_x;  // calcula direção x do raio
        ray->dir_y = game->player->y_direction + game->player->plane_y * ray->camera_x;  // calcula direção y do raio
        ray->delta_dist_x = fabs(1 / ray->dir_x);  // o quanto o raio tem que andar naquela direção antes de cruzar uma linha do grid.
        ray->delta_dist_y = fabs(1 / ray->dir_y);
        calculate_ray_direction(game, ray);
        perform_dda(game, ray);
        calculate_wall_distance(ray);
        calculate_wall_height(ray);
        draw_vertical_lines(game, ray, x);
        x++;
    }
}
