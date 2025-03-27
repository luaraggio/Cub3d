
#include "../../includes/cub3d_bonus.h"

static int	count_players(t_map *map, int i, int *player_count);

int	valid_map_chars(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
	{
		if (line_is_direction(map->map_file[i]) == NO_ERROR)
			i++;
		else if (line_is_f_or_c(map->map_file[i]) == NO_ERROR)
			i++;
		else if (line_belongs_to_map(map->map_file[i]) == NO_ERROR)
			i++;
		else
		{
			my_printf_error(RED "Error\n" \
				"Invalid characters have been found\n" RESET);
			return (ERROR);
		}
	}
	return (NO_ERROR);
}

int	valid_player(t_map *map)
{
	int	i;
	int	player_count;

	i = 0;
	player_count = 0;
	while (line_belongs_to_map(map->map_file[i]) == ERROR)
		i++;
	if (count_players(map, i, &player_count) == ERROR)
		return (ERROR);
	if (player_count != 1)
	{
		my_printf_error(RED "Error.\nThere must be one player, and only one,"
			"in the map\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	count_players(t_map *map, int i, int *player_count)
{
	int	j;

	while (map->map_file[i])
	{
		j = 0;
		while (map->map_file[i][j])
		{
			if (is_player(map->map_file[i][j]) == NO_ERROR)
				(*player_count)++;
			j++;
		}
		i++;
	}
	return (NO_ERROR);
}
