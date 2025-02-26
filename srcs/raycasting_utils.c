/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:26:26 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/26 00:33:42 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Initializes the raycasting structure for the game.
 *
 * O que faz?
 *  - Inicializa a estrutura t_raycast, responsável por armazenar as informações
 do raio.
    - Zera todos os valores da estrutura com my_bzero.
    - Define a posição inicial do raio (pos_x, pos_y) como a posição do jogador.
    - Define a direção inicial do raio (dir_x, dir_y) com base na direção do
 jogador.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains
 *             player information.
 */

 int init_raycasting(t_game *game)
{
    t_raycast *ray;

    ray = malloc(sizeof(t_raycast));
    if (!ray) return (ERROR);
    my_bzero(ray, sizeof(t_raycast));
    game->ray = ray;
    ray->pos_x = (int)game->player->x;
    ray->pos_y = (int)game->player->y;
    ray->dir_x = game->player->x_direction;
    ray->dir_y = game->player->y_direction;
    return (NO_ERROR);
}

/**
 * @brief Determines the initial step direction and side distances for
 * raycasting.
 *
 * O que faz?
 *  - Define os valores de step_x e step_y, que indicam se o raio se move para
 * frente (+1) ou para trás (-1) no mapa.
 * - Calcula side_dist_x e side_dist_y, que representam a distância que o raio
 * precisa percorrer até alcançar a primeira borda da célula do mapa.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains
 *             player information.
 * @param ray Poninter to raycast structure (`t_raycast`), wich contains ray
 *             information;
 */

void calculate_ray_direction(t_game *game, t_raycast *ray)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->pos_x - game->player->x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (game->player->x + 1.0 - ray->pos_x) * ray->delta_dist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->pos_y - game->player->y) * ray->delta_dist_x;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (game->player->y + 1.0 - ray->pos_y) * ray->delta_dist_y;
    }
}

/**
 * @brief It's a loop that increments the ray with 1 square every time, until a
 * wall is hit.
 *
 * O que faz?
 *  - Utiliza os valores que calculamos anteriormente (sideDistX e sideDistY)
 * para determinar se o raio avança primeiro no eixo X ou no eixo Y.
 * - Cada passo no loop move o raio para a próxima célula do mapa até ele encontrar
 * uma parede.
 *
 * @param game Pointer to the main game structure (`t_game`), which contains
 *             player information.
 * @param ray Poninter to raycast structure (`t_raycast`), wich contains ray
 *             information;
 */

void perform_dda(t_game *game, t_raycast *ray)
{
    // perform DDA
     while (ray->hit == 0)
     {
         // jump to next map square, either in x-direction, or in y-direction
         if (ray->side_dist_x < ray->side_dist_y)  // o raio atingirá primeiro uma borda vertical (entre colunas).
         {
             ray->side_dist_x += ray->delta_dist_x;  // atualiza side_dist_x para o próximo ponto de interseção no X
             game->player->x += ray->step_x;  // move o jogador uma célula no eixo X
             ray->side = VERTICAL_SIDE;
         }
         else  // o raio atingirá primeiro uma borda horizontal (entre linhas).
         {
             ray->side_dist_y += ray->delta_dist_y;
             game->player->y += ray->step_x;  // move o jogador uma célula no eixo X
             ray->side = HORIZONTAL_SIDE;
         }
     }
     if (game->map->map_int[(int)ray->pos_x][(int)ray->pos_y] == '1')
         ray->hit = 1;
 }

/**
 * @brief Calculate distance of perpendicular ray (Euclidean distance would
 * givefisheye effect!)
 *
 * O que faz?
 *  - Calcula a altura da parede na tela depois que o raio atinge uma parede
 *no mapa.
 * - Usa a distância perpendicular do raio até a parede (perp_wall_dist) para
 * determinar o tamanho da linha que deve ser desenhada no centro da tela.
 *
 * @param ray Poninter to raycast structure (`t_raycast`), wich contains ray
 *             information;
 */

void calculate_wall_height(t_raycast *ray)
{
    if (ray->side == VERTICAL_SIDE)
        ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
    else
        ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
    ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist); // Calculate height of line to draw on screen
    ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2; // calculate lowest pixel to fill in current stripe
    if (ray->draw_start < 0) ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2; //// calculate highest pixel to fill in current stripe
    if (ray->draw_end >= W_HEIGHT) ray->draw_end = W_HEIGHT - 1;
}

/**
 * @brief Calcula a distância perpendicular do jogador até a parede e
 * corrige o tamanho das paredes na tela para que a perspectiva fique
 * correta.
 *
 * O que faz?
 *  - Calcula wall_x para saber exatamente onde o raio colidiu dentro
 * do bloco.
 *  - Ajuda a escolher qual parte da textura da parede deve ser usada.
 *
 * @param ray Poninter to raycast structure (`t_raycast`), wich contains ray
 *             information;
 */

 void calculate_wall_distance(t_raycast *ray)
 {
    // Removido: int texture_number;
    // Removido: texture_number = game->map->map_int[ray->map_x][ray->map_y] - 1;

     /*
      * Calcula a posição exata (no eixo da parede) onde o raio atingiu a parede.
      * Se a parede é vertical (ou seja, o raio atingiu uma borda vertical) usamos a coordenada Y,
      * senão usamos a coordenada X.
      */
     if (ray->side == VERTICAL_SIDE)
         ray->wall_x = ray->pos_y + ray->perp_wall_dist * ray->dir_y;
     else
         ray->wall_x = ray->pos_x + ray->perp_wall_dist * ray->dir_x;

     // Pega somente a parte fracionária de wall_x (a posição relativa na célula)
     ray->wall_x -= floor(ray->wall_x);

     /*
      * Calcula qual coluna da textura (coordenada X) deve ser usada.
      * Multiplicamos o valor fracionário wall_x pelo tamanho da textura.
      */
     ray->texture_x = (int)(ray->wall_x * (double)TEXTURE_SIZE);

     /*
      * Se a parede foi atingida de determinados lados, invertemos a coordenada da textura
      * para que ela fique orientada corretamente.
      */
     if (ray->side == VERTICAL_SIDE && ray->dir_x > 0)
         ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
     if (ray->side == HORIZONTAL_SIDE && ray->dir_y < 0)
         ray->texture_x = TEXTURE_SIZE - ray->texture_x - 1;
 }
