
#include "../includes/cub3d.h"

int	check_args(int argc)
{
	if (argc != 2)
	{
		my_printf_error(RED "Error\n" "Usage: ./cub3d <map.cub>\n" RESET);
		exit(ERROR);
	}
	return (NO_ERROR);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_game		game;
	t_player	player;

	my_bzero(&map, sizeof(t_map));
	my_bzero(&player, sizeof(t_player));
	my_bzero(&game, sizeof(t_game));
	check_args(argc);
	my_printf(PINK "Hi! Welcome to our project! 🦋🐙\n" RESET);
	if (set_map(&map, argv[1]) == ERROR)
		return (ERROR);
	play_cub3d(&game, &map, &player);
	clear_map(&map);
}
