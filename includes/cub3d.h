/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:11:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/15 15:38:01 by lraggio          ###   ########.fr       */
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

//Size
# define W_HEIGHT 640
# define W_WIDTH 480

# include "mlx/mlx.h"
# include "mlx/mlx.h"
# include "my_libft/libft.h"
# include "enums.h"
# include "structs.h"
# include <stdio.h>

//main.c
int	main(int argc, char **argv);

//game.c
int start_game(void);

//------------------MAP------------------
// map.c
int     set_map(t_map *map, char *map_file);
// map_validation.c
int     valid_map(t_map *map);
int 	valid_map_file(char *map_file);
int     map_is_last(t_map *map);
// ceiling_and_floor.c
int     valid_ceiling_and_floor(t_map *map);
// walls.c
int	valid_walls(t_map *map);

int     valid_walls(t_map *map);
// is_map.c
int     is_map(char **map);
int     character_belongs_to_map(char c, char next);
int     is_player(char c);
int     map_start(t_map *map);
// line_is.c 
int 	line_belongs_to_map(char *line);
int     line_is_direction(char *line);
int     line_is_f_or_c(char *line);
// char_validation.c
int     valid_map_chars(t_map *map);
int     valid_player(t_map *map);
// floodfeel.c
int     map_is_closed(t_map *map);
int     floodfeel(char **map, int i, int j, int total_i);
int     check_first_and_last_line(t_map *map);
// get_map_data.c
int     get_rows(t_map *map);
int     get_cols(t_map *map);
int     get_total_i(t_map *map);
// texture.c
void    set_textures_names(t_map *map, char *map_line);
int		open_texture(t_map *map);
#endif
