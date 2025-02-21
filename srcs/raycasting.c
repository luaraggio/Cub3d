/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/21 17:33:46 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*

------------------------------- Raycasting ------------------------------
Setar valores para struct de raycasting
Calcular a direção do raio
Enxertar a posição do jogador no mapa
Calcular o tamanho do raio entre dois pontos (o ptempo que o raio leva para
atravessar um quadrado)


Calcular direção do raio direita, esqueda, cima e baixo
Calcular a distancia do raio até a próxima parede
Algoritmo de DDA (quando encontro uma parede)
Calcular a distância do jogador até a parede e corrigir a distorção da
perspectiva
Calcular a altura da parede

------------------------ Desenhar --------------------------------------
Desenhar linhas verticais
Desenhar minimapa

*/

int	init_raycasting(t_game *game)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (ERROR);
	my_bzero(ray, sizeof(t_raycast));
	game->ray = ray;
	ray->pos_x = (int)game->player->x;
	ray->pos_y = (int)game->player->y;
	ray->dir_x = game->player->x_direction;
	ray->dir_y = game->player->y_direction;
	return (NO_ERROR);
}


void	ray_direction(t_game *game, t_raycast *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sideDistX = (ray->pos_x - game->player->x) * ray->deltaDistX;
	}
	else
	{
		ray->step_x = 1;
		ray->sideDistX = (game->player->x + 1.0 - ray->pos_x) * ray->deltaDistX;
	}
	if (ray->dir_y < 0)
	{
		ray->step_x = -1;
		ray->sideDistY = (ray->pos_y - game->player->y) * ray->deltaDistX;
	}
	else
	{
		ray->step_y = 1;
		ray->sideDistY = (game->player->y + 1.0 - ray->pos_y) * ray->deltaDistY;
	}
}

//It's a loop that increments the ray with 1 square every time, until a wall is hit.
void	dda(t_game *game, t_raycast *ray)
{
	//perform DDA
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			game->player->x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			game->player->y += ray->step_x;
			ray->side = 1;
		}
	}
	//Check if ray has hit a wall
	/*if (game->map->map_int[x][y] > 0)
		ray->hit = 1;*/

	//TROCAR X E Y PELOS ÍNDICES NO MAPA DE INTEIROS
}

/*

 The direction of the ray can be calculated as was explained earlier: as the 
 sum of the direction vector, and a part of the plane vector. 

*/

void	raycasting(t_game *game, t_raycast *ray)
{
	int	x;

	x = 0;
	while (x < W_WIDTH)
	{
		ray->camera_x = 2 * x / W_WIDTH -1;
		ray->dir_x = game->player->x_direction + game->player->plane_x * ray->camera_x;
		ray->dir_y = game->player->y_direction + game->player->plane_y * ray->camera_x;
		ray->deltaDistX = fabs(1 / ray->dir_x);
		ray->deltaDistY = fabs(1 / ray->dir_y);
		ray_direction(game, ray);
		dda(game, ray);
		x++;
	}
}