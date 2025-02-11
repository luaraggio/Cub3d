/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:34:17 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/06 19:34:18 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rgb_is_valid(t_map *map, int i, int j);

int	valid_ceiling_and_floor(t_map *map)
{
	int	i;
	int	j;
	int	c_flag;
	int	f_flag;

	i = 0;
	c_flag = 0;
	f_flag = 0;
	while (map->map_file[i] && line_belongs_to_map(map->map_file[i]) == ERROR)
	{
		j = 0;
		while (map->map_file[i][j] && line_belongs_to_map(map->map_file[i]) == ERROR)
		{
			if (map->map_file[i][j] == 'C')
			{
				c_flag++;
				if (rgb_is_valid(map, i, j++) == ERROR)
					return (ERROR);
			}
			else if (map->map_file[i][j] == 'F')
			{
				f_flag++;
				if (rgb_is_valid(map, i, j++) == ERROR)
					return (ERROR);
			}
			else if (map->map_file[i][j] != ' ')
				break ;
			j++;
		}
		i++;
	}
	if (c_flag == 0 || f_flag == 0)
	{
		my_printf_error(RED "Error\n" "Ceiling or floor not found\n" RESET);
		return (ERROR);
	}
	else if (c_flag > 1 || f_flag > 1)
	{
		my_printf_error(RED "Error\n" "There can be only one floor and only one ceiling\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	rgb_is_valid(t_map *map, int i, int j)
{
	int		num;
	int		rgb_size;
	char	*str_n;
	int		line_size;

	num = 0;
	rgb_size = 0;
	str_n = NULL;
	line_size = my_strlen(map->map_file[i]);
	while (j <= line_size && map->map_file[i][j])
	{
		if ((my_isnum(map->map_file[i][j]) != 0 || map->map_file[i][j] == '-' || map->map_file[i][j] == '+') && rgb_size < 3)
		{
			rgb_size++;
			if (rgb_size < 3 && my_strchr(&map->map_file[i][j], ',') != NULL)
				str_n = my_strcdup(&map->map_file[i][j], ',');
			else
				str_n = my_strcdup(&map->map_file[i][j], '\0');
			num = atoi(str_n);
			j += my_strlen(str_n);
			free(str_n);
			str_n = NULL;
			if (num < 0 || num > 255)
			{
				my_printf_error(RED "Error\n" "Invalid RGB value\n" RESET);
				return (ERROR);
			}
		}
		j++;
	}
	if (rgb_size != 3)
	{
		my_printf_error(RED "Error\n" "Invalid RGB format\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}
