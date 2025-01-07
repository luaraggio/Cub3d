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
//	printf("Valid map\n");
	if (valid_ceiling_and_floor(map) == ERROR)
		return (ERROR);
/*	if (valid_walls(map) == ERROR)
		return (ERROR);
	if (map_is_last(map) == ERROR)
		return (ERROR);
	if (valid_map_chars(map) == ERROR)
		return (ERROR);
	if (valid_player(map) == ERROR)
		return (ERROR);
	if (floodfeel(map) == ERROR)
		return (ERROR);*/
	return (NO_ERROR);
}