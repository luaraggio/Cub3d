/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/21 14:38:31 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"
# include <stdbool.h>

typedef struct s_image		t_image;
typedef struct s_textures	t_textures;
typedef struct s_player		t_player;
typedef struct s_raycast	t_raycast;

typedef struct s_map
{
	char					*full_map;
	char					**map_file;
	char					**map;
	int						**map_int;
	int						i_start;
	int						total_i;
	int						player_j;
	int						player_i;
	char					player_direction;
	unsigned int			floor_color;
	unsigned int			ceiling_color;
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
	t_image					*north_texture_img;
	t_image					*south_texture_img;
	t_image					*west_texture_img;
	t_image					*east_texture_img;
}							t_textures;

typedef struct s_game
{
	void					*mlx;
	void					*win;
	bool					keys[TOTAL_KEYS];
	t_image					*image;
	t_map					*map;
	t_player				*player;
	t_raycast				*ray;
}							t_game;

typedef struct s_player
{
	double					x;
	double					y;
	double					x_direction;
	double					y_direction;
	double					plane_x;
	double					plane_y;
	double					move_speed;
	double					rotation_speed;
}							t_player;

typedef struct s_raycast
{
	double					camera_x;
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					side_dist_x;
	double					side_dist_y;
	double					perp_wall_dist;
	double					wall_x;
	int						map_x;
	int						map_y;
	int						line_height;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						draw_start;
	int						draw_end;
	int						texture_x;
}							t_raycast;

typedef struct s_image
{
	void					*img;
	char					*addr;
	int						bpp;
	int						endian;
	int						size_line;
	int						size_height;
}							t_image;

typedef struct s_map2d
{
	char					**map_2d;
	int						map_width;
	int						map_height;
	double					max_width;
	double					max_height;
	double					scale;
	double					player_x;
	double					player_y;
	double					player_size;
	int						player_color;
	int						wall_color;
}							t_map2d;

#endif
