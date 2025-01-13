/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:21:37 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/12 11:21:39 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_rows(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return i - 6;
}

int	get_cols(t_map *map)
{
	int	i;
	int	j;
	int	max_row;

	i = 0;
	max_row = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (i >= 6 && j > max_row)
			max_row = j;
		i++;
	}
	return max_row;
}

int	get_total_i(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return (i - 1);
}