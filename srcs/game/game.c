
#include "../../includes/cub3d.h"

int	exit_game(t_game *game)
{
	clear_all(game, game->map);
	exit(EXIT_SUCCESS);
	return (NO_ERROR);
}

void	set_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 3, 1L << 1, release_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}

int	game_loop(t_game *game)
{
	print_game(game);
	return (0);
}

void	play_cub3d(t_game *game, t_map *map, t_player *player)
{
	init_game(game, map, player);
	create_texture_imgs(map->textures, game);
	create_general_img(game->mlx, game->image);
	set_hooks(game);
}
