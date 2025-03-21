/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:14:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/21 16:14:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_individual_extension_xpm( \
		char *full_direction, char *direction_nick);

int	check_textures_extension(t_map *map)
{
	int	ret;

	ret = NO_ERROR;
	ret += check_individual_extension_xpm \
			(map->textures->north_texture, "north");
	ret += check_individual_extension_xpm \
			(map->textures->south_texture, "south");
	ret += check_individual_extension_xpm(map->textures->west_texture, "west");
	ret += check_individual_extension_xpm(map->textures->east_texture, "east");
	if (ret != NO_ERROR)
	{
		close_texture_fds(map);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	check_individual_extension_xpm( \
		char *full_direction, char *direction_nick)
{
	int	size;

	size = my_strlen(full_direction);
	if (full_direction[size - 4] != '.' || full_direction[size - 3] != 'x' || \
		full_direction[size - 2] != 'p' || full_direction[size - 1] != 'm')
	{
		my_printf_error(RED "Error\n" \
			"Invalid file extension for %s texture\n" RESET, direction_nick);
		return (ERROR);
	}
	return (NO_ERROR);
}
