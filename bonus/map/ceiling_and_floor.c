
#include "../../includes/cub3d_bonus.h"

static int	parse_ceiling_and_floor(t_map *map, int *c_flag, int *f_flag);
static int	process_ceiling(t_map *map, int i, int *j, int *c_flag);
static int	process_floor(t_map *map, int i, int *j, int *f_flag);

int	valid_ceiling_and_floor(t_map *map)
{
	int	c_flag;
	int	f_flag;

	c_flag = 0;
	f_flag = 0;
	if (parse_ceiling_and_floor(map, &c_flag, &f_flag) == ERROR)
		return (ERROR);
	if (c_flag == 0 || f_flag == 0)
	{
		my_printf_error(RED "Error\n" "Ceiling or floor not found\n" RESET);
		return (ERROR);
	}
	else if (c_flag > 1 || f_flag > 1)
	{
		my_printf_error(RED "Error\n"
			"There can be only one floor and only one ceiling\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	parse_ceiling_and_floor(t_map *map, int *c_flag, int *f_flag)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_file[i] && line_belongs_to_map(map->map_file[i]) == ERROR)
	{
		j = 0;
		while (map->map_file[i][j]
			&& line_belongs_to_map(map->map_file[i]) == ERROR)
		{
			if (process_ceiling(map, i, &j, c_flag) == ERROR)
				return (ERROR);
			if (process_floor(map, i, &j, f_flag) == ERROR)
				return (ERROR);
			else if (map->map_file[i][j] != ' ')
				break ;
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}

static int	process_ceiling(t_map *map, int i, int *j, int *c_flag)
{
	if (map->map_file[i][*j] == 'C')
	{
		(*c_flag)++;
		if (rgb_is_valid(map, i, (*j)++) == ERROR)
			return (ERROR);
	}
	return (NO_ERROR);
}

static int	process_floor(t_map *map, int i, int *j, int *f_flag)
{
	if (map->map_file[i][*j] == 'F')
	{
		(*f_flag)++;
		if (rgb_is_valid(map, i, (*j)++) == ERROR)
			return (ERROR);
	}
	return (NO_ERROR);
}
