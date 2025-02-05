/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/05 03:10:23 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef struct s_map
{
	char	*full_map;
	char	**map;
	int		i_start;
	int		total_i;
	int		rows;
	int		cols;
	int		height;// altura
	int		width;// largura
	int		player_j;
	int		player_i;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		fd_north_texture;
	int		fd_south_texture;
	int		fd_west_texture;
	int		fd_east_texture;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		w_height;
	int		w_width;
	int		last_key;
	t_map	*map;
}			t_game;

typedef struct s_player
{
	double	x; //posição do jogador no mapa
	double	y;
	double	x_direction; //direção que o jogador está olhando
	double	y_direction;
	double	plane_x; //plano da câmera para visão periférica
	double	plane_y;
	double	move_speed;
	double	rotation_speed;
}			t_player;

#endif
