/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:26:26 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/20 19:56:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
    if (!ray)
        return (ERROR);
    my_bzero(ray, sizeof(t_raycast));
    game->ray = ray;
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
        ray->side_dist_x = (game->player->x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - game->player->x) * ray->delta_dist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (game->player->y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - game->player->y) * ray->delta_dist_y;
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
//    printf("Entrou no perform_dda\n");
    // perform DDA
     while (ray->hit == 0)
     {
//        printf("Entrou no while do perform_dda com ray->hit = %i\n", ray->hit);
         // jump to next map square, either in x-direction, or in y-direction
         if (ray->side_dist_x < ray->side_dist_y)  // o raio atingirá primeiro uma borda vertical (entre colunas).
         {
//            printf("Entrou no if de perform_dda com side_dist_x = %f e side_dist_y = %f\n", ray->side_dist_x, ray->side_dist_y);
             ray->side_dist_x += ray->delta_dist_x;  // atualiza side_dist_x para o próximo ponto de interseção no X
             ray->map_x += ray->step_x;  // move o jogador uma célula no eixo X
             ray->side = VERTICAL_SIDE;
         }
         else  // o raio atingirá primeiro uma borda horizontal (entre linhas).
         {
//            printf("Entrou no else de perform_dda com side_dist_x = %f e side_dist_y = %f\n", ray->side_dist_x, ray->side_dist_y);
             ray->side_dist_y += ray->delta_dist_y;
             ray->map_y += ray->step_y;  // move o jogador uma célula no eixo Y
             ray->side = HORIZONTAL_SIDE;
         }
         if (game->map->map_int[ray->map_y][ray->map_x] == 1)
             ray->hit = 1;
     }
//     printf("Saiu do loop de perform_dda\n");
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
    ray->line_height = (int)(W_HEIGHT / ray->perp_wall_dist); // Calculate height of line to draw on screen
    ray->draw_start = -ray->line_height / 2 + W_HEIGHT / 2; // calculate lowest pixel to fill in current stripe
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + W_HEIGHT / 2; //// calculate highest pixel to fill in current stripe
    if (ray->draw_end >= W_HEIGHT)
        ray->draw_end = W_HEIGHT - 1;
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

/*
 * Calcula a posição exata (no eixo da parede) onde o raio atingiu a parede.
 * Se a parede é vertical (ou seja, o raio atingiu uma borda vertical) usamos a coordenada Y,
 * senão usamos a coordenada X.
 */
 /*void calculate_wall_distance(t_game *game, t_raycast *ray)
 {
     if (ray->side == VERTICAL_SIDE)
         ray->wall_x = game->player->y + ray->perp_wall_dist * ray->dir_y;
     else
         ray->wall_x = game->player->x + ray->perp_wall_dist * ray->dir_x;
     // Pega somente a parte fracionária de wall_x (a posição relativa na célula)
     ray->wall_x -= floor(ray->wall_x);
 }*/

 void calculate_wall_distance(t_game *game, t_raycast *ray)
 {
     if (ray->side == VERTICAL_SIDE)
     {
        ray->perp_wall_dist = (ray->map_x - game->player->x + (1 - ray->step_x) / 2) / ray->dir_x;
        ray->wall_x = game->player->y + ray->perp_wall_dist * ray->dir_y;
     }
     else
     {
        ray->perp_wall_dist = (ray->map_y - game->player->y + (1 - ray->step_y) / 2) / ray->dir_y;
        ray->wall_x = game->player->x + ray->perp_wall_dist * ray->dir_x;
     }
     // Pega somente a parte fracionária de wall_x (a posição relativa na célula)
     ray->wall_x -= floor(ray->wall_x);
 }
