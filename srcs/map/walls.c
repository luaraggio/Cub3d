/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:32:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/15 18:07:48 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	direction_ok(t_map *map, char *direction);
static int	validate_texture(t_map *map);

int	valid_walls(t_map *map)
{
	int	err_flag;

	err_flag = OFF;
//	printf("Vai validar as paredes\n");
	if (direction_ok(map, "NO") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "SO") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "WE") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "EA") == ERROR)
		err_flag = ON;
	if (err_flag == ON)
		return (ERROR);
//	printf("Vai validar as texturas\n");
	if (validate_texture(map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	direction_ok(t_map *map, char *direction)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
//	printf("Vai checar a direção em %s\n", direction);
	while (map->map[i] && line_belongs_to_map(map->map[i]) == ERROR)
	{
		j = 0;
//		printf("Linha %d: %s\n", i, map->map[i]);
		while (map->map[i][j] && line_belongs_to_map(map->map[i]) == ERROR)
		{
			if (my_strncmp(&(map->map[i][j]), direction, 2) == 0)
			{
				flag++;
				if (flag <= 1)
					set_texture(map, map->map[i], direction);
				break ;
			}
			else if (map->map[i][j] != ' ')
				break ;
			j++;
		}
		i++;
	}
	if (flag != 1)
	{
		my_printf_error(RED "Error\n" "There must be one, and only one, %s\n" RESET, direction);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	validate_texture(t_map *map)
{
	if (check_textures_extension(map) != NO_ERROR)
		return (ERROR);
	if (open_texture(map) != NO_ERROR)
		return (ERROR);
	return (NO_ERROR);
}