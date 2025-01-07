/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:11:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/03 23:11:58 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//Colors
# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"

# include "mlx/mlx.h"
# include "my_libft/libft.h"
# include "enums.h"
# include "structs.h"
# include <stdio.h>

//main.c
int	main(int argc, char **argv);
//------------------MAP------------------
// map.c
int	set_map(t_map *map, char *map_file);
// map_validation.c
int	valid_map(t_map *map);
int	valid_file(char *map_file);
int map_is_last(t_map *map);
// ceiling_and_floor.c
int	valid_ceiling_and_floor(t_map *map);
// walls.c
int	valid_walls(t_map *map);
#endif
