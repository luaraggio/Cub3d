/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:21:19 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/05 21:21:23 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	open_map(t_map *map, char *map_file);
static void	set_struct(t_map *map);
static int	get_rows(t_map *map);
static int	get_cols(t_map *map);

int	set_map(t_map *map, char *map_file)
{
	if (open_map(map, map_file) == ERROR)
		return ERROR;
	set_struct(map);
	return NO_ERROR;
}

static int	open_map(t_map *map, char *map_file)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		my_printf_error(RED "Error\n" "Could not open the file %s\n" RESET, map_file);
		return ERROR;
	}
	while (42)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		map->full_map = my_strjoin_cleaning(map->full_map, ret);
		if (ret)
		{
			free(ret);
			ret = NULL;
		}
	}
	close(fd);
	my_printf("Map: \n%s\n", map->full_map);
	return (NO_ERROR);
}

static void	set_struct(t_map *map)
{
	map->map = my_split(map->full_map, '\n');
	free(map->full_map);
	map->full_map = NULL;
	map->rows = get_rows(map);
	map->cols = get_cols(map);
}

static int	get_rows(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	return i - 6;
}

static int	get_cols(t_map *map)
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