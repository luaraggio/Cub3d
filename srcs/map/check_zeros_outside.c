
#include "../../includes/cub3d.h"

static int	check_zeros_in_lines_start(t_map *smap, char **map);
static int	check_zeros_in_lines_end(t_map *smap, char **map);
static int	check_zeros_in_columns_start(t_map *smap, char **map);
static int	check_zeros_in_columns_end(t_map *smap, char **map);

int	map_is_closed_by_walls(t_map *map)
{
	if (check_zeros_in_lines_start(map, map->map_file) == ERROR)
		return (ERROR);
	if (check_zeros_in_lines_end(map, map->map_file) == ERROR)
		return (ERROR);
	if (check_zeros_in_columns_start(map, map->map_file) == ERROR)
		return (ERROR);
	if (check_zeros_in_columns_end(map, map->map_file) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	check_zeros_in_lines_start(t_map *smap, char **map)
{
	int	i;
	int	j;

	i = smap->i_start;
	while (smap->map_file[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] == '1' || j == (int)my_strlen(map[i]))
			i++;
		else if (map[i][j] == '0')
		{
			my_printf_error(RED "Error\n"
				"Map is not closed by walls\n" RESET);
			return (ERROR);
		}
	}
	return (NO_ERROR);
}

static int	check_zeros_in_lines_end(t_map *smap, char **map)
{
	int	i;
	int	j;

	i = smap->i_start;
	while (smap->map_file[i])
	{
		j = my_strlen(map[i]) - 1;
		while (j != 0 && map[i][j] == ' ')
			j--;
		if (map[i][j] == '1' || j == 0)
			i++;
		else if (map[i][j] == '0')
		{
			my_printf_error(RED "Error\n" \
				"Map is not closed by walls\n" RESET);
			return (ERROR);
		}
	}
	return (NO_ERROR);
}

static int	check_zeros_in_columns_start(t_map *smap, char **map)
{
	int	i;
	int	j;

	i = smap->i_start;
	j = 0;
	while (j < (int)my_strlen(map[i]))
	{
		i = smap->i_start;
		while (i <= smap->total_i)
		{
			if (map[i][j] == '1' || i == smap->total_i)
				break ;
			else if (map[i][j] == '0')
			{
				my_printf_error(RED "Error\n" \
					"Map is not closed by walls\n" RESET);
				return (ERROR);
			}
			i++;
		}
		j++;
	}
	return (NO_ERROR);
}

static int	check_zeros_in_columns_end(t_map *smap, char **map)
{
	int	i;
	int	j;

	i = smap->total_i;
	j = 0;
	while (j < (int)my_strlen(map[i]))
	{
		i = smap->total_i;
		while (i >= smap->i_start)
		{
			if (map[i][j] == '1' || i == smap->i_start)
				break ;
			else if (map[i][j] == '0')
			{
				my_printf_error(RED "Error\n"
					"Map is not closed by walls\n" RESET);
				return (ERROR);
			}
			i--;
		}
		j++;
	}
	return (NO_ERROR);
}
