
#include "../../includes/cub3d.h"

static int	process_rgb_value(t_map *map, int i, int *j, int *rgb_size);
static int	check_rgb_size(int rgb_size);

int	rgb_is_valid(t_map *map, int i, int j)
{
	int		rgb_size;
	int		line_size;

	rgb_size = 0;
	line_size = my_strlen(map->map_file[i]);
	while (j <= line_size && map->map_file[i][j])
	{
		if ((my_isnum(map->map_file[i][j]) != 0 \
				|| map->map_file[i][j] == '+') && rgb_size < 3)
		{
			if (process_rgb_value(map, i, &j, &rgb_size) == ERROR)
				return (ERROR);
		}
		else if (map->map_file[i][j] == '-')
			return (check_rgb_size(rgb_size));
		j++;
	}
	return (check_rgb_size(rgb_size));
}

static int	process_rgb_value(t_map *map, int i, int *j, int *rgb_size)
{
	int		num;
	char	*str_n;

	str_n = NULL;
	(*rgb_size)++;
	if (*rgb_size < 3 && my_strchr(&map->map_file[i][*j], ',') != NULL)
		str_n = my_strcdup(&map->map_file[i][*j], ',');
	else
		str_n = my_strcdup(&map->map_file[i][*j], '\0');
	num = atoi(str_n);
	*j += my_strlen(str_n);
	free(str_n);
	str_n = NULL;
	if (num < 0 || num > 255)
	{
		my_printf_error(RED "Error\n" "Invalid RGB value\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	check_rgb_size(int rgb_size)
{
	if (rgb_size != 3)
	{
		my_printf_error(RED "Error\n" "Invalid RGB format\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}
