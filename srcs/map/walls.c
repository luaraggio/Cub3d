
#include "../../includes/cub3d.h"

static int	direction_ok(t_map *map, char *direction);
static int	validate_texture(t_map *map);
static int	check_direction_line(t_map *map, char *direction, int j, int flag);

int	valid_walls(t_map *map)
{
	int	err_flag;

	err_flag = OFF;
	if (direction_ok(map, "NO") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "SO") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "WE") == ERROR)
		err_flag = ON;
	if (direction_ok(map, "EA") == ERROR)
		err_flag = ON;
	if (err_flag == ON)
		return (ERROR);
	if (validate_texture(map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	direction_ok(t_map *map, char *direction)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map->map_file[i] && line_belongs_to_map(map->map_file[i]) == ERROR)
	{
		flag = check_direction_line(map, direction, i, flag);
		i++;
	}
	if (flag != 1)
	{
		my_printf_error(RED "Error\n" \
					"There must be one, and only one, %s\n" RESET, \
				direction);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	check_direction_line(t_map *map, char *direction, int i, int flag)
{
	int	j;

	j = 0;
	while (map->map_file[i][j]
		&& line_belongs_to_map(map->map_file[i]) == ERROR)
	{
		if (my_strncmp(&(map->map_file[i][j]), direction, 2) == 0)
		{
			flag++;
			if (flag <= 1)
				set_texture(map, map->map_file[i], direction);
			break ;
		}
		else if (map->map_file[i][j] != ' ')
			break ;
		j++;
	}
	return (flag);
}

static int	validate_texture(t_map *map)
{
	if (check_textures_extension(map) != NO_ERROR)
		return (ERROR);
	if (open_texture(map) != NO_ERROR)
		return (ERROR);
	return (NO_ERROR);
}
