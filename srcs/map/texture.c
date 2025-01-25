/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:29:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/15 18:08:44 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_texture(t_map *map, char *map_line, char *direction)
{
	int	j;

	j = 2;
//	printf("EM SET TEXTURE: \nDirection = %s\nmap_line[%i] = %c\n", direction, j, map_line[j]);
	while (map_line[j] && map_line[j] == ' ')
		j++;
//	printf("EM SET TEXTURE: depois do while com map_line[%i] = %c\n", j, map_line[j]);
	if (my_strcmp(direction, "NO") == 0)
		map->north_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "SO") == 0)
		map->south_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "WE") == 0)
		map->west_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "EA") == 0)
		map->east_texture = my_strdup(&(map_line[j]));
//	printf("NO = %s\n", map->north_texture);
//	printf("SO = %s\n", map->south_texture);
//	printf("WE = %s\n", map->west_texture);
//	printf("EA = %s\n", map->east_texture);
}

int	open_texture(t_map *map)
{
	map->fd_north_texture = open(map->north_texture, O_RDONLY);
	if (map->fd_north_texture == -1)
		return (my_printf_error(RED "Error\n" "Unable to open texture north\n" RESET));
	map->fd_south_texture = open(map->south_texture, O_RDONLY);
	if (map->fd_south_texture == -1)
	{
		close(map->fd_north_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture south\n" RESET));
	}
	map->fd_west_texture = open(map->west_texture, O_RDONLY);
	if (map->fd_west_texture == -1)
	{
		close(map->fd_north_texture);
		close(map->fd_south_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture west\n" RESET));
	}
//	printf("Vai abrir a textura leste, %s\n", map->east_texture);
	map->fd_east_texture = open(map->east_texture, O_RDONLY);
//	printf("map->fd_east_texture == %d\n", map->fd_east_texture);
	if (map->fd_east_texture == -1)
	{
		close(map->fd_north_texture);
		close(map->fd_south_texture);
		close(map->fd_west_texture);
		return (my_printf_error(RED "Error\n" "Unable to open texture east\n" RESET));
	}
	return (NO_ERROR);
}

int	check_textures_extension(t_map *map)
{
	int	size;
	
	size = my_strlen(map->north_texture);
	if (map->north_texture[size - 4] != '.' || map->north_texture[size - 3] != 'x' || map->north_texture[size - 2] != 'p' || map->north_texture[size - 1] != 'm')
		return (my_printf_error(RED "Error\n" "Invalid file extension for north texture\n" RESET));
	size = my_strlen(map->south_texture);
	if (map->south_texture[size - 4] != '.' || map->south_texture[size - 3] != 'x' || map->south_texture[size - 2] != 'p' || map->south_texture[size - 1] != 'm')
		return (my_printf_error(RED "Error\n" "Invalid file extension for south texture\n" RESET));
	size = my_strlen(map->west_texture);
	if (map->west_texture[size - 4] != '.' || map->west_texture[size - 3] != 'x' || map->west_texture[size - 2] != 'p' || map->west_texture[size - 1] != 'm')
		return (my_printf_error(RED "Error\n" "Invalid file extension for west texture\n" RESET));
	size = my_strlen(map->east_texture);
	if (map->east_texture[size - 4] != '.' || map->east_texture[size - 3] != 'x' || map->east_texture[size - 2] != 'p' || map->east_texture[size - 1] != 'm')
		return (my_printf_error(RED "Error\n" "Invalid file extension for east texture\n" RESET));
	return (NO_ERROR);
}