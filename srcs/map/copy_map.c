
#include "../../includes/cub3d.h"

static void	malloc_map(t_map *map);

void	copy_map(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = map->i_start;
	j = 0;
	k = 0;
	malloc_map(map);
	while (map->map_file[i])
	{
		j = 0;
		while (map->map_file[i][j])
		{
			map->map[k][j] = map->map_file[i][j];
			j++;
		}
		k++;
		i++;
	}
}

static void	malloc_map(t_map *map)
{
	int	i;
	int	k;
	int	j;

	i = map->i_start;
	k = 0;
	j = 0;
	map->map = my_calloc(map->total_i - map->i_start + 2, sizeof(char **));
	while (map->map_file[i])
	{
		j = 0;
		while (map->map_file[i][j])
			j++;
		map->map[k] = my_calloc(j + 1, sizeof(char *));
		i++;
		k++;
	}
}

void	map_to_int(t_map *map)
{
	int	i;
	int	j;

	map->map_int = my_calloc(map->total_i - map->i_start + 2, sizeof(int **));
	i = 0;
	j = 0;
	while (map->map[i])
	{
		map->map_int[i] = my_calloc(my_strlen(map->map[i]) + 1, sizeof(int *));
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				map->map_int[i][j] = 1;
			else
				map->map_int[i][j] = 0;
			j++;
		}
		i++;
	}
}
