/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/12 15:02:50 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"
# include <stdbool.h>

typedef struct s_image		t_image;
typedef struct s_textures	t_textures;

typedef struct s_map
{
	char					*full_map;
	char **map_file;
		// É o arquivo .cub inteiro. Mudar o nome dessa variável para criar a cópia apenas no mapa
	char					**map;
	int i_start;                // Uso para a check_first_and_last_line, logo antes da floodfill
	int total_i;                // Uso na floodfill
	int player_j;               // Vetor position do jogador em x
	int player_i;               // Vetor position do jogador em y
	char player_direction;      // Direção que o jogador está olhando
	unsigned int floor_color;   // Já em hexadecimal
	unsigned int ceiling_color; // Já em hexadecimal
	t_textures				*textures;
}							t_map;

typedef struct s_textures
{
	char					*north_texture;
	char					*south_texture;
	char					*west_texture;
	char					*east_texture;
	int						fd_north_texture;
	int						fd_south_texture;
	int						fd_west_texture;
	int						fd_east_texture;
}							t_textures;

typedef struct s_game
{
	void					*mlx;
	void					*win;
	int						*keys;
	t_map					*map;
	t_image					*image;
}							t_game;

typedef struct s_player
{
	double x; // posição do jogador no mapa
	double					y;
	double x_direction; // direção que o jogador está olhando
	double					y_direction;
	double plane_x; // plano da câmera para visão periférica
	double					plane_y;
	double					move_speed;
	double					rotation_speed;
}							t_player;

typedef struct s_image
{
	void					*img;
	char					*addr;
	int						bpp;
	int						endian;
	int						size_line;
	int						size_height;
}							t_image;
#endif
