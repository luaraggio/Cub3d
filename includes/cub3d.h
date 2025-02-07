/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:11:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/17 21:18:48 by lraggio          ###   ########.fr       */
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

//Keycodes

# define ESC_KEY 65307
# define Q_KEY 113
# define UP_KEY 65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

//Size
# define W_HEIGHT 800
# define W_WIDTH 1300

# include "mlx/mlx.h"
# include "my_libft/libft.h"
# include "enums.h"
# include "structs.h"
# include <stdio.h>

//main.c
int	main(int argc, char **argv);

//game.c
int init_game_struct(t_game *game, t_map *map);
int exit_game(t_game *game);
int	set_hooks(t_game *game);
int start_game(t_game *game, t_map *map);

//keys.c
void	print_key(const char *key_name, const char *color);
int press_key(int keycode, t_game *game);

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
void	set_texture(t_map *map, char *map_line, char *direction);
int		open_texture(t_map *map);
int		check_textures_extension(t_map *map);
// clear.c
void	clear_map(t_map *map);
void	close_texture_fds(t_map *map);
void	clear_all(t_game *game, t_map *map);
void	clear_game(t_game *game);
// color.c
unsigned int		get_color(t_map *map, char ref);
char	*dec_to_hex(int n);

//------------------PRINT_GAME------------------
// print_game.c
void	print_game(t_game *game, t_map *map);

#endif
