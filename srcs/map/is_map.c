/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:08:15 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/07 23:08:16 by lpaixao-         ###   ########.fr       */
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

int	line_belongs_to_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '\n' || line[i] != '\0') && character_belongs_to_map(line[i], line[i + 1]) == ERROR)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int character_belongs_to_map(char c, char next)
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