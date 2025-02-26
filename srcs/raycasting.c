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

/**
 * @brief Initializes the raycasting structure for the game.
 *
 * O que faz?
 *  - Inicializa a estrutura t_raycast, responsável por armazenar as informações do raio.
    - Zera todos os valores da estrutura com my_bzero.
    - Define a posição inicial do raio (pos_x, pos_y) como a posição do jogador.
    - Define a direção inicial do raio (dir_x, dir_y) com base na direção do jogador.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains
 *             player information.
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

/**
 * @brief Determines the initial step direction and side distances for raycasting.
 *
 * O que faz?
 *  - Define os valores de step_x e step_y, que indicam se o raio se move para frente (+1)
 *            ou para trás (-1) no mapa.
 * - Calcula sideDistX e sideDistY, que representam a distância que o raio precisa percorrer
 *            até alcançar a primeira borda da célula do mapa.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains
 *             player information.
 * @param ray Poninter to raycast structure (`t_raycast`), wich contains ray
 *             information;
 */

void	calculate_ray_direction(t_game *game, t_raycast *ray)
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
		ray->step_y = -1;
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
	int	x;
	int	y;

	x = 0;
	y = 0;
	//perform DDA
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->sideDistX < ray->sideDistY)  //o raio atingirá primeiro uma borda vertical (entre colunas).
		{
			ray->sideDistX += ray->deltaDistX;
			game->player->x += ray->step_x;
			ray->side = VERTICAL_SIDE;
		}
		else //o raio atingirá primeiro uma borda horizontal (entre linhas).
		{
			ray->sideDistY += ray->deltaDistY; //atualiza sideDistX para o próximo ponto de interseção no X
			game->player->y += ray->step_x; //move o jogador uma célula no eixo X
			ray->side = HORIZONTAL_SIDE;
		}
	}
	//Check if ray has hit a wall
	x = game->player->x;
	y = game->player->y;
	if (game->map->map_int[x][y] == '1')
		ray->hit = 1;
}

void	calculate_wall_height(t_raycast *ray)
{
	//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
	if (ray->side == 0)
		ray->perp_wall_dist = ray->sideDistX - ray->deltaDistX;
	else
		ray->perp_wall_dist = ray->sideDistY - ray->deltaDistY;
	//Calculate height of line to draw on screen
	ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	ray->draw_start = - ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2;
	if (ray->draw_end >= W_HEIGHT)
		ray->draw_end = W_HEIGHT - 1;
}

/*
A função raycasting(t_game *game, t_raycast *ray) é a responsável por lançar os raios na tela 
da cub3d e determinar onde eles atingem as paredes do mapa, permitindo a construção da visão 
em primeira pessoa.

- Funcionamento:

Varre a tela do jogo coluna por coluna (de x = 0 até W_WIDTH), lançando um raio para cada coluna 
de pixels. Cada raio viaja em uma direção específica e, ao atingir uma parede, determina a distância 
da parede ao jogador.

Permite calcular a altura da parede e desenhá-la corretamente na tela.
*/

void	raycasting(t_game *game, t_raycast *ray)
{
	int	x;

	x = 0;
	while (x < W_WIDTH) //lança um raio para cada coluna da tela, da esquerda pra direita
	{
		ray->camera_x = 2 * x / W_WIDTH -1;
		ray->dir_x = game->player->x_direction + game->player->plane_x * ray->camera_x; //calcula direção x do raio
		ray->dir_y = game->player->y_direction + game->player->plane_y * ray->camera_x; //calcula direção y do raio
		ray->deltaDistX = fabs(1 / ray->dir_x); //
		ray->deltaDistY = fabs(1 / ray->dir_y);
		calculate_ray_direction(game, ray);
		dda(game, ray);
		//wall_distance
		calculate_wall_height(ray);
		//draw vertical lines
		x++;
	}
}