/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:33:33 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/05 15:22:53 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_is_closed(t_map *map)
{
	char **map_copy;

	map_copy = my_copy_matrix(map->map_file);
	if (check_first_and_last_line(map) == ERROR || floodfill(map_copy, map->player_i, map->player_j, map->total_i) == ERROR)
	{
		my_clean_vect(map_copy);
		my_printf_error(RED "Error\n" "Map is not closed\n" RESET);
		return (ERROR);
	}
	my_clean_vect(map_copy);
	return (NO_ERROR);
}

int	floodfill(char **map, int i, int j, int total_i)
{
	int error;

	error = NO_ERROR;
	map[i][j] = '1';
	if (error != ERROR && map[i][j + 1] == '0')
		error = floodfill(map, i, j + 1, total_i);
	else if (error != ERROR && map[i][j + 1] != '1')
		return (ERROR);
	if (error != ERROR && map[i][j - 1] == '0')
		error = floodfill(map, i, j - 1, total_i);
	else if (error != ERROR && map[i][j - 1] != '1')
		return (ERROR);
	if (error != ERROR && (i < total_i) && map[i + 1][j] == '0')
		error = floodfill(map, i + 1, j, total_i);
	else if (error != ERROR && ((i == total_i) || map[i + 1][j] != '1'))
		return (ERROR);
	if (error != ERROR && map[i - 1][j] == '0')
		error = floodfill(map, i - 1, j, total_i);
	else if (error != ERROR && map[i - 1][j] != '1')
		return (ERROR);
	return (error);
}

int	check_first_and_last_line(t_map *map)
{
	int j;

	j = 0;
	while (map->map_file[map->i_start][j])
	{
		if (map->map_file[map->i_start][j] != '1')
			return (ERROR);
		j++;
	}
	j = 0;
	while (map->map_file[map->total_i][j])
	{
		if (map->map_file[map->total_i][j] != '1')
			return (ERROR);
		j++;
	}
	return (NO_ERROR);
}
