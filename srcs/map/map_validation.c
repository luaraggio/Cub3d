
#include "../../includes/cub3d.h"

static int	map_is_empty(t_map *map);
static int	check_map_line(t_map *map, int i);

int	valid_map_file(char *map_file)
{
	if (map_file[my_strlen(map_file) - 4] != '.'
		|| map_file[my_strlen(map_file) - 3] != 'c'
		|| map_file[my_strlen(map_file) - 2] != 'u'
		|| map_file[my_strlen(map_file) - 1] != 'b')
	{
		my_printf_error(RED "Error\n" "Invalid file extension\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

int	valid_map(t_map *map)
{
	if (map_is_empty(map) == ERROR)
		return (ERROR);
	if (valid_map_chars(map) == ERROR)
		return (ERROR);
	if (map_is_last(map) == ERROR)
		return (ERROR);
	if (valid_ceiling_and_floor(map) == ERROR)
		return (ERROR);
	if (valid_walls(map) == ERROR)
		return (ERROR);
	if (valid_player(map) == ERROR)
		return (ERROR);
	if (map_is_closed(map) == ERROR)
		return (ERROR);
	if (map_is_closed_by_walls(map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

int	map_is_last(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (check_map_line(map, i) == NO_ERROR)
			return (NO_ERROR);
		i--;
	}
	return (ERROR);
}

static int	check_map_line(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->map_file[i][j])
	{
		if (map->map_file[i][j] == '1' || map->map_file[i][j] == '0')
			return (NO_ERROR);
		else if (map->map_file[i][j] == ' ' || \
				map->map_file[i][j] == 'N' || \
				map->map_file[i][j] == 'S' || \
				map->map_file[i][j] == 'E' || \
				map->map_file[i][j] == 'W')
			j++;
		else
		{
			my_printf_error(RED "Error\n"
				"There must be a map at the end of the file\n" RESET);
			return (ERROR);
		}
	}
	return (NO_ERROR);
}

static int	map_is_empty(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_file[i])
	{
		if (map->map_file[i][1])
		{
			while (map->map_file[i][j])
			{
				if (map->map_file[i][j] != ' ')
					return (NO_ERROR);
				j++;
			}
		}
		i++;
	}
	my_printf_error(RED "Error\n" "Empty map\n" RESET);
	return (ERROR);
}
