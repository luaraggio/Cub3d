/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:03 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/14 23:21:37 by lraggio          ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		moves;
	int		w_height;
	int		w_width;
}			t_game;

#endif
