/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/25 23:13:40 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>

#include "enums.h"

typedef struct s_image t_image;
typedef struct s_textures t_textures;
typedef struct s_player t_player;
typedef struct s_raycast t_raycast;

typedef struct s_map
{
    char *full_map;
    char **map_file; // É o arquivo .cub inteiro. Mudar o nome dessa variável para criar a cópia apenas no mapa
    char **map;
    int **map_int;
    int i_start;   // Uso para a check_first_and_last_line, logo antes da floodfill
    int total_i;   // Uso na floodfill
    int player_j;  // Vetor position do jogador em x
    int player_i;  // Vetor position do jogador em y
    char player_direction;       // Direção que o jogador está olhando
    unsigned int floor_color;    // Já em hexadecimal
    unsigned int ceiling_color;  // Já em hexadecimal
    t_textures *textures;
} t_map;

typedef struct s_textures
{
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;
    int fd_north_texture;
    int fd_south_texture;
    int fd_west_texture;
    int fd_east_texture;
    t_image *north_texture_img;
    t_image *south_texture_img;
    t_image *west_texture_img;
    t_image *east_texture_img;
} t_textures;

typedef struct s_game
{
    void *mlx;
    void *win;
    bool keys[TOTAL_KEYS];
    t_image *image;
    t_map *map;
    t_player *player;
    t_raycast *ray;
} t_game;

typedef struct s_player
{
    double x;
    double y;
    double x_direction;
    double y_direction;
    double plane_x;
    double plane_y;
    double move_speed;
    double rotation_speed;
} t_player;

typedef struct s_raycast
{
    double camera_x;  // x-coordinate in camera space: permite olhar apenas para os lados
    double pos_x;     // posição x do raio: começa como pos(x) do personagem
    double pos_y;     // posição y do raio: começa como pos(y) do personagem
    double dir_x;     // direção x do raio: começa como dir(x) do personagem
    double dir_y;     // direção y do raio: começa como dir(y) do personagem
    double delta_dist_x;  // distância entre duas bordas verticais
    double delta_dist_y;  // distância entre duas bordas horizontais
    double side_dist_x;   // distância que o raio precisa percorrer até antingir uma borda horizontal (quando o raio cruza uma linha entre colunas no mapa).
    double side_dist_y;  // distância que o raio precisa percorrer até antingir uma borda vertical (quando o raio cruza uma linha entre linhas no mapa).
    double perp_wall_dist; //distância perpendicular do raio até a parede
    double wall_x; //posição exata de onde o raio bateu na parede
    int line_height;  // altura da parede
    int step_x;  // step_x e step_y determinam a direção do movimento do raio na grade do mapa.
    int step_y;
    int hit;   // pra saber se bateu ou não em uma parede
    int side;  // vai ser 1 se tiver batido primeiro em uma borda vertical, vai ser 0 se tiver batido em uma borda horizontal
    int draw_start;  // Ponto mais alto da parede
    int draw_end;    // Ponto mais baixo da parede
    int texture_x; // Coluna da textura para ser usada na parede
} t_raycast;

typedef struct s_image
{
    void *img;
    char *addr;
    int bpp;
    int endian;
    int size_line;
    int size_height;
} t_image;

typedef struct s_map2d
{
    char **map_2d;
    int map_width;
    int map_height;
    double max_width;
    double max_height;
    double scale;
    double player_x;
    double player_y;
    double player_size;
    int player_color;
    int wall_color;
} t_map2d;

#endif
