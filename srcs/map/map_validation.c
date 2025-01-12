/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:13:07 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/06 16:13:10 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	map_is_empty(t_map *map);

int	valid_file(char *map_file)
{
	if (map_file[my_strlen(map_file) - 4] != '.' || map_file[my_strlen(map_file) - 3] != 'c' || map_file[my_strlen(map_file) - 2] != 'u' || map_file[my_strlen(map_file) - 1] != 'b')
	{
		my_printf_error(RED "Error\n" "Invalid file extension\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

int	valid_map(t_map *map)
{
	int	err_flag;

	err_flag = OFF;
	if (map_is_empty(map) == ERROR)
		return(ERROR);
	if (valid_map_chars(map) == ERROR)
		return (ERROR);
	if (map_is_last(map) == ERROR)
		return (ERROR);
	if (valid_ceiling_and_floor(map) == ERROR)
		err_flag = ON;
	if (valid_walls(map) == ERROR)
		err_flag = ON;
	if (err_flag == ON)
		return (ERROR);
	if (valid_player(map) == ERROR)
		return (ERROR);
	if (map_is_closed(map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

int	map_is_last(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0')
				return (NO_ERROR);
			else if (map->map[i][j] == ' ' || map->map[i][j] == 'N' || \
					map->map[i][j] == 'S' || \
					map->map[i][j] == 'E' || map->map[i][j] == 'W')
				j++;
			else
			{
				my_printf_error(RED "Error\n" "There must be a map at the end of the file\n" RESET);
				return (ERROR);
			}
		}
		i--;
	}
	return (NO_ERROR);
}

static int	map_is_empty(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		if (map->map[i][1])
		{
			while (map->map[i][j])
			{
				if (map->map[i][j] != ' ')
					return NO_ERROR;
				j++;
			}
		}
		i++;
	}
	my_printf_error(RED "Error\n" "Empty map\n" RESET);
	return (ERROR);
}