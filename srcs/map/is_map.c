/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:08:15 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/21 13:41:49 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_belongs_to_map(map[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	character_belongs_to_map(char c, char next)
{
	if (c == ' ' || c == '1' || c == '0')
		return (NO_ERROR);
	else if (c == 'N' && next != 'O')
		return (NO_ERROR);
	else if (c == 'S' && next != 'O')
		return (NO_ERROR);
	else if (c == 'W' && next != 'E')
		return (NO_ERROR);
	else if (c == 'E' && next != 'A')
		return (NO_ERROR);
	else
		return (ERROR);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (NO_ERROR);
	return (ERROR);
}

int	map_start(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
	{
		if (is_map(&(map->map_file[i])) == NO_ERROR)
			return (i);
		i++;
	}
	return (0);
}
