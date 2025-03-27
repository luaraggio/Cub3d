
#include "../../includes/cub3d_bonus.h"

static int	open_map(t_map *map, char *map_file);

int	set_map(t_map *map, char *map_file)
{
	if (open_map(map, map_file) == ERROR)
		return (ERROR);
	if (valid_map_file(map_file) == ERROR)
	{
		free(map->full_map);
		map->full_map = NULL;
		return (ERROR);
	}
	set_initial_map_struct(map);
	if (valid_map(map) != NO_ERROR)
	{
		free_imgs(map->textures);
		clear_map(map);
		return (ERROR);
	}
	finish_map_struct(map);
	return (NO_ERROR);
}

static int	open_map(t_map *map, char *map_file)
{
	int		fd;
	char	*ret;

	ret = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		my_printf_error(RED "Error\n"
			"Could not open the file %s\n" RESET, map_file);
		return (ERROR);
	}
	while (42)
	{
		ret = get_next_line(fd);
		if (ret == NULL)
			break ;
		map->full_map = my_strjoin_cleaning(map->full_map, ret);
	}
	close(fd);
	if (!map->full_map)
	{
		my_printf_error(RED "Error\nEmpty map\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}
