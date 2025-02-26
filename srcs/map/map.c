/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:21:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/15 15:39:47 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_map(t_map *map, char *map_file);
static void	set_initial_map_struct(t_map *map);
static void	finish_map_struct(t_map *map);
static void	set_player_start(t_map *map);

int	set_map(t_map *map, char *map_file)
{
	if (open_map(map, map_file) == ERROR)
		return ERROR;
	if (valid_map_file(map_file) == ERROR)
	{
		free(map->full_map);
		map->full_map = NULL;
		return (ERROR);
	}
	set_initial_map_struct(map);
	if (valid_map(map) != NO_ERROR)
	{
		clear_map(map);
		return (ERROR);
	}
	finish_map_struct(map);
	return (NO_ERROR);
}

static int	open_map(t_map *map, char *map_file)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		my_printf_error(RED "Error\n" "Could not open the file %s\n" RESET, map_file);
		return ERROR;
	}
	while (42)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		map->full_map = my_strjoin_cleaning(map->full_map, ret);
	}
	close(fd);
	if (!map->full_map)
	{
		my_printf_error(RED "Error\n" "Empty map\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static void	set_initial_map_struct(t_map *map)
{
	map->map_file = my_split(map->full_map, '\n');
	free(map->full_map);
	map->full_map = NULL;
	map->total_i = get_total_i(map);
	map->i_start = map_start(map);
	set_player_start(map);
	map->ceiling_color = OFF;
	map->floor_color = OFF;
	map->textures = (t_textures *)malloc(sizeof(t_textures));
	my_bzero(map->textures, sizeof(t_textures));
}

static void	finish_map_struct(t_map *map)
{
	map->floor_color = get_color(map, 'F');
	map->ceiling_color = get_color(map, 'C');
	copy_map(map);
}

static void	set_player_start(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while ((i < map->total_i) && line_belongs_to_map(map->map_file[i]) == ERROR)
        i++;
	while (map->map_file[i])
	{
		j = 0;
		while (map->map_file[i][j])
		{
			if (is_player(map->map_file[i][j]) == NO_ERROR)
			{
				map->player_j = j;
				map->player_i = i;
				map->player_direction = map->map_file[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}