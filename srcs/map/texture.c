/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:29:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/12 20:29:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_texture(t_map *map, char *map_line, char *direction);

void	set_textures_names(t_map *map, char *map_line)
{
	set_texture(map, map_line, "NO");	
	set_texture(map, map_line, "SO");
	set_texture(map, map_line, "WE");
	set_texture(map, map_line, "EA");
}

static void	set_texture(t_map *map, char *map_line, char *direction)
{
	int	j;

	j = 0;
	while (map_line[j] && map_line[j] == ' ')
		j++;
	if (my_strncmp(map_line, direction, 2) == 0)
	{
		j += 2;
		while (map_line[j] && map_line[j] == ' ')
			j++;
//		printf("Texture %s: %s, com j = %i em %c\n", direction, &(map_line[j]), j, map_line[j]);
		if (my_strcmp(direction, "NO") == 0)
			map->north_texture = my_strdup(&(map_line[j]));
		else if (my_strcmp(direction, "SO") == 0)
			map->south_texture = my_strdup(&(map_line[j]));
		else if (my_strcmp(direction, "WE") == 0)
			map->west_texture = my_strdup(&(map_line[j]));
		else if (my_strcmp(direction, "EA") == 0)
			map->east_texture = my_strdup(&(map_line[j]));
	}
}

int	open_texture(t_map *map)
{
	map->fd_north_texture = open(map->north_texture, O_RDONLY);
	if (map->fd_north_texture == -1)
		return (my_printf_error(RED "Error\n" "Unable to open texture north\n" RESET));
	map->fd_south_texture = open(map->north_texture, O_RDONLY);
	if (map->fd_south_texture == -1)
	{
		close(map->fd_north_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture south\n" RESET));
	}
	map->fd_west_texture = open(map->north_texture, O_RDONLY);
	if (map->fd_west_texture == -1)
	{
		close(map->fd_north_texture);
		close(map->fd_south_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture west\n" RESET));
	}
	map->fd_east_texture = open(map->north_texture, O_RDONLY);
	if (map->fd_east_texture == -1)
	{
		close(map->fd_north_texture);
		close(map->fd_south_texture);
		close(map->fd_west_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture east\n" RESET));
	}
	return (NO_ERROR);
}