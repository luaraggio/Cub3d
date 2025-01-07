/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/07 19:51:22 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "enums.h"

typedef struct s_map
{
	char		*full_map;
	char		**map;
	int			rows;
	int			cols;

	int			height; //altura
	int			width; //largura
}				t_map;

typedef struct s_window
{
	int			w_height; //altura
	int			w_width; //largura
}			t_window;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	struct s_map *map;
	struct s_window *window;
}			t_game;

#endif
