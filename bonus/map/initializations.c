/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:18:05 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/25 13:03:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	start_textures(t_textures *textures);
static void	set_player_start(char **map, t_map *st_map, int flag_start);

void	set_initial_map_struct(t_map *map)
{
	map->map_file = my_split(map->full_map, '\n');
	free(map->full_map);
	map->full_map = NULL;
	map->total_i = get_total_i(map);
	map->i_start = map_start(map);
	set_player_start(map->map_file, map, ON);
	map->ceiling_color = OFF;
	map->floor_color = OFF;
	map->textures = (t_textures *)malloc(sizeof(t_textures));
	my_bzero(map->textures, sizeof(t_textures));
	start_textures(map->textures);
}

void	finish_map_struct(t_map *map)
{
	map->floor_color = get_color(map, 'F');
	map->ceiling_color = get_color(map, 'C');
	copy_map(map);
	set_player_start(map->map, map, OFF);
	map_to_int(map);
}

static void	start_textures(t_textures *textures)
{
	textures->north_texture = NULL;
	textures->south_texture = NULL;
	textures->west_texture = NULL;
	textures->east_texture = NULL;
	textures->fd_north_texture = -1;
	textures->fd_south_texture = -1;
	textures->fd_west_texture = -1;
	textures->fd_east_texture = -1;
	textures->north_texture_img = (t_image *)malloc(sizeof(t_image));
	textures->south_texture_img = (t_image *)malloc(sizeof(t_image));
	textures->west_texture_img = (t_image *)malloc(sizeof(t_image));
	textures->east_texture_img = (t_image *)malloc(sizeof(t_image));
}

static void	set_player_start(char **map, t_map *st_map, int flag_start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flag_start == ON && (i < st_map->total_i)
		&& line_belongs_to_map(st_map->map_file[i]) == ERROR)
		i++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]) == NO_ERROR)
			{
				st_map->player_j = j;
				st_map->player_i = i;
				st_map->player_direction = map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}
