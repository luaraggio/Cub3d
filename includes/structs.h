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
	char		*noth_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			fd_noth_texture;
	int			fd_south_texture;
	int			fd_west_texture;
	int			fd_east_texture;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	int		w_height;
	int		w_width;
}			t_game;

#endif
