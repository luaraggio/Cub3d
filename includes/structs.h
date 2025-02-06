/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/15 15:38:26 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef struct s_image	t_image;

typedef struct s_map
{
	char		*full_map;
	char		**map;
	int			i_start;
	int			total_i;
	int			rows;
	int			cols;
	int			height; //altura
	int			width; //largura
	int			player_j;
	int			player_i;
	int			floor_color;
	int			ceiling_color;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			fd_north_texture;
	int			fd_south_texture;
	int			fd_west_texture;
	int			fd_east_texture;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	*image;
	int		moves;
	int		w_height;
	int		w_width;
	t_map	*map;
}			t_game;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
	int		size_line;
	int		size_height;
}			t_image;
#endif
