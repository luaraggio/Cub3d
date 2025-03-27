
#include "../../includes/cub3d_bonus.h"

int	init_game(t_game *game, t_map *map, t_player *player)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (ERROR);
	my_bzero(image, sizeof(t_image));
	game->map = map;
	game->image = image;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		my_printf_error(RED "Error\n Something went wrong with "
			"mlx initialization\n" RESET);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (ERROR);
	}
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "Cub3d");
	reset_key_array(game);
	init_player(game, player);
	init_raycasting(game);
	return (NO_ERROR);
}

int	init_player(t_game *game, t_player *player)
{
	game->player = player;
	player->x = game->map->player_j + 0.5;
	player->y = game->map->player_i + 0.5;
	player->x_direction = 0;
	player->y_direction = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED;
	set_player_position(game, player);
	return (NO_ERROR);
}

int	init_raycasting(t_game *game)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (ERROR);
	my_bzero(ray, sizeof(t_raycast));
	game->ray = ray;
	return (NO_ERROR);
}
