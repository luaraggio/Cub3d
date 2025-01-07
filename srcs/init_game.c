#include "../includes/cub3d.h"

/*



*/

int init_window(t_game *game)
{
    /*int	counter;
	int	width;

	width = my_strlen(game->map->map[0]);
	game->map_width = width * IMAGE_SIZE;
	counter = 0;
	while (game->map[counter])
		counter++;
	game->map_height = counter * IMAGE_SIZE;*/
    game->map->height = 100 * 100;
    game->map->width = 100 * 100;
    return (NO_ERROR);
}

/*

If mlx_init() fails to set up the connection to the graphical system, it will return NULL, 
otherwise a non-null pointer is returned as a connection identifier.

*/

int game_init(t_game *game)
{
    if ((game->mlx = mlx_init()) == NULL)
    {
        my_printf_error(RED "Error. Something went wrong with image initialization\n" RESET);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (ERROR);
    }
    init_window(game);
    game->win = mlx_new_window(game->mlx, game->map->width, game->map->height, "Cub3d 🤖");
	//game->moves = 0;
	//declare_images(game);
    return (NO_ERROR);
}