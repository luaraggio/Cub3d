
#include "../../includes/cub3d.h"

int	get_total_i(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file[i])
		i++;
	return (i - 1);
}
