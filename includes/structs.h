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

//typedef struct s_all_images	t_all_images;
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
//	t_all_images	*images;
}			t_game;

/*typedef struct s_all_images
{
//	void	*img_north;
//	void	*img_south;
//	void	*img_west;
//	void	*img_east;
//	void	*img_sprite;
	t_image	*rectangle_ceiling;
	t_image	*rectangle_floor;
}			t_all_images;*/

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		endian;
//	int		bits_per_pixel;
	int		size_line;
	int		size_height;
}			t_image;
#endif
