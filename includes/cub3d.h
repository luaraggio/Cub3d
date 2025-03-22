/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:11:57 by lraggio           #+#    #+#             */
/*   Updated: 2025/03/21 15:39:49 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "enums.h"
# include "mlx/mlx.h"
# include "my_libft/libft.h"
# include "structs.h"
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define ESC_KEY 65307
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define Q_KEY 113
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define L_SHIFT_KEY 65505
# define R_SHIFT_KEY 65506
# define W_HEIGHT 800
# define W_WIDTH 1300
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.1
# define VERTICAL_SIDE 0
# define HORIZONTAL_SIDE 1

// Texture Size
# define TEXTURE_SIZE 64
# define MINIMAP_PROPORTION 0.2

// main.c
int				main(int argc, char **argv);

//------------------GAME------------------//

// game.c
void			set_hooks(t_game *game);
void			play_cub3d(t_game *game, t_map *map, t_player *player);
int				exit_game(t_game *game);
void			create_general_img(void *mlx, t_image *img);
int				game_loop(t_game *game);

// initializations.c
int				init_game(t_game *game, t_map *map, t_player *player);
int				init_player(t_game *game, t_player *player);
int				init_raycasting(t_game *game);

//------------------PLAYER---------------//

// player.c
void			set_player_position(t_game *game, t_player *player);
void			update_player_position(t_game *game);

// keys.c
void			reset_key_array(t_game *game);
int				press_key(int keycode, t_game *game);
int				release_key(int keycode, t_game *game);

// moves.c
void			move_player_forward(t_game *game, t_player *player);
void			move_player_backward(t_game *game, t_player *player);
void			move_player_to_left(t_game *game, t_player *player);
void			move_player_to_right(t_game *game, t_player *player);

// rotate.c
void			rotate_player_to_left(t_player *player);
void			rotate_player_to_right(t_player *player);

//------------------RAYCASTING-----------//
// raycasting.c
void			set_ray_values(t_game *game, t_raycast *ray, int x);
void			raycasting(t_game *game, t_raycast *ray);

// raycasting_utils.c
void			calculate_ray_direction(t_game *game, t_raycast *ray);
void			perform_dda(t_game *game, t_raycast *ray);
void			calculate_wall_height(t_raycast *ray);
void			calculate_wall_distance(t_game *game, t_raycast *ray);

// raycasting_render.c
void			select_texture(t_game *game, t_raycast *ray, t_image **texture);
void			draw_texture_column(t_game *game, t_image *texture,
					t_raycast *ray, int x);
void			draw_vertical_lines(t_game *game, t_raycast *ray, int x);
int				calculate_tex_x(t_raycast *ray);
int				calculate_tex_y(int y, t_raycast *ray);

//------------------MAP------------------//

// map.c
int				set_map(t_map *map, char *map_file);
// initializations.c
void			set_initial_map_struct(t_map *map);
void			finish_map_struct(t_map *map);
// map_validation.c
int				valid_map(t_map *map);
int				valid_map_file(char *map_file);
int				map_is_last(t_map *map);
// ceiling_and_floor.c
int				valid_ceiling_and_floor(t_map *map);
// rgb.c
int				rgb_is_valid(t_map *map, int i, int j);
// walls.c
int				valid_walls(t_map *map);
// is_map.c
int				is_map(char **map);
int				character_belongs_to_map(char c, char next);
int				is_player(char c);
int				map_start(t_map *map);
// line_is.c
int				line_belongs_to_map(char *line);
int				line_is_direction(char *line);
int				line_is_f_or_c(char *line);
// char_validation.c
int				valid_map_chars(t_map *map);
int				valid_player(t_map *map);
// floodfill.c
int				map_is_closed(t_map *map);
int				floodfill(char **map, int i, int j, int total_i);
int				check_extremities(t_map *map);
// get_map_data.c
int				get_total_i(t_map *map);
// texture.c
void			set_textures_names(t_map *map, char *map_line);
void			set_texture(t_map *map, char *map_line, char *direction);
int				open_texture(t_map *map);
void			create_texture_imgs(t_textures *textures, t_game *game);
void			get_img_data_adds(t_textures *textures);
// texture_extension.c
int				check_textures_extension(t_map *map);
// color.c
unsigned int	get_color(t_map *map, char ref);
char			*dec_to_hex(int n);
// copy_map.c
void			copy_map(t_map *map);
void			map_to_int(t_map *map);
// check_zeros_outside.c
int				map_is_closed_by_walls(t_map *map);

//------------------PRINT_GAME------------------//

// print_game.c
void			print_game(t_game *game);
void			my_mlx_pixel_put(t_image *image, int i, int j, int color);
// print_2d.c
void			print_2dmap(t_game *game, char **map_2d, t_player *player);
void			print_minigame(t_game *game, t_map2d *map_2d);

// print_2d_utils.c
void			found_wall(t_game *game, t_map2d *map_2d, int i, int j);
int				get_opposite_color(int color);
void			draw_player(t_game *game, t_map2d *map2d);
void			draw_line_to_wall(t_game *game, t_map2d *map2d);

//------------------UTILS---------------------//

// general_clear.c
void			clear_all(t_game *game, t_map *map);
void			clear_map(t_map *map);
void			clear_game(t_game *game);

// clear_textures.c
void			clear_texture_map(t_map *map);
void			close_texture_fds(t_map *map);
void			destroy_texture_imgs(t_game *game, t_textures *textures);
void			free_imgs(t_textures *textures);

#endif
