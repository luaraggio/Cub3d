
#include "../../../includes/cub3d_bonus.h"

void	print_2dmap(t_game *game, char **map_2d, t_player *player)
{
	t_map2d	map2d;
	double	scale_x;
	double	scale_y;
	int		current_width;

	(void)player;
	my_bzero(&map2d, sizeof(t_map2d));
	map2d.map_2d = map_2d;
	map2d.max_width = W_WIDTH * MINIMAP_PROPORTION;
	map2d.max_height = W_HEIGHT * MINIMAP_PROPORTION;
	map2d.player_color = get_opposite_color(game->map->ceiling_color
			- 0x202020);
	map2d.wall_color = get_opposite_color(game->map->ceiling_color);
	map2d.map_height = 0;
	while (map_2d[map2d.map_height])
	{
		current_width = my_strlen(map_2d[map2d.map_height]);
		if (current_width > map2d.map_width)
			map2d.map_width = current_width;
		map2d.map_height++;
	}
	scale_x = (double)map2d.max_width / map2d.map_width;
	scale_y = (double)map2d.max_height / map2d.map_height;
	map2d.scale = fmin(scale_x, scale_y);
	print_minigame(game, &map2d);
}

void	print_minigame(t_game *game, t_map2d *map_2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map_2d->map_height)
	{
		j = 0;
		while (j < map_2d->map_width)
		{
			if (map_2d->map_2d[i][j] == '1')
				found_wall(game, map_2d, i, j);
			j++;
		}
		i++;
	}
	draw_player(game, map_2d);
	draw_line_to_wall(game, map_2d);
}
