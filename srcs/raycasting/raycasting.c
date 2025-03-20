/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/20 20:09:14 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void draw_vertical_lines(t_game *game, t_raycast *ray, int x) {
    int y;
	int d;
    int tex_x;
    int tex_y;
    t_image *texture;

	d = 0;
	y = 0;
    // Escolhe a textura correta com base na direção do raio
    if (ray->side == VERTICAL_SIDE)
	{
        if (ray->dir_x > 0)
            texture = game->map->textures->south_texture_img;
        else
            texture = game->map->textures->north_texture_img;
    }
	else
	{
        if (ray->dir_y > 0)
            texture = game->map->textures->east_texture_img;
        else
            texture = game->map->textures->west_texture_img;
    }

	// Calcula tex_x
	tex_x = (int)(ray->wall_x * (double)TEXTURE_SIZE);
	if ((ray->side == VERTICAL_SIDE && ray->dir_x > 0) || (ray->side == HORIZONTAL_SIDE && ray->dir_y < 0))
		tex_x = TEXTURE_SIZE - tex_x - 1; // Espelha a textura se necessário
	y = ray->draw_start;
	// Loop para cada pixel vertical
    while (y < ray->draw_end)
	{
        // Calcula tex_y
        d = y * 256 - W_HEIGHT * 128 + ray->line_height * 128; // Ajuste de posição
        tex_y = ((d * TEXTURE_SIZE) / ray->line_height) / 256;

        // Obtém a cor da textura
        unsigned int color = *(unsigned int *)(texture->addr + (tex_y * texture->size_line + tex_x * (texture->bpp / 8)));

        // Desenha o pixel na tela
        my_mlx_pixel_put(game->image, y, x, color);
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
	ray->map_x = (int)game->player->x;
	ray->map_y = (int)game->player->y;
	// o quanto o raio tem que andar naquela direção antes de cruzar uma linha do grid.
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	raycasting(t_game *game, t_raycast *ray)
{
	//printf("Oi da funcao de raycasting\n");
	int	x;

	x = 0;
	while (x < W_WIDTH)
	 /* Lança um raio para cada coluna da tela, da esquerda pra direita*/
	{
		/*ray->map_x = (int)game->player->x;
		ray->map_y = (int)game->player->y;
		ray->hit = 0;*/
		set_ray_values(game, ray, x);
		calculate_ray_direction(game, ray);
		perform_dda(game, ray);
		calculate_wall_distance(game, ray);
		calculate_wall_height(ray);
		draw_vertical_lines(game, ray, x);
		x++;
	}
}
