
#include "../../includes/cub3d_bonus.h"

void	reset_key_array(t_game *game)
{
	int	i;

	i = 0;
	while (i < TOTAL_KEYS)
	{
		game->keys[i] = false;
		i++;
	}
}

int	release_key(int keycode, t_game *game)
{
	if (keycode == RIGHT_KEY)
		game->keys[RIGHT_INDEX] = false;
	else if (keycode == LEFT_KEY)
		game->keys[LEFT_INDEX] = false;
	else if (keycode == W_KEY)
		game->keys[W_INDEX] = false;
	else if (keycode == S_KEY)
		game->keys[S_INDEX] = false;
	else if (keycode == A_KEY)
		game->keys[A_INDEX] = false;
	else if (keycode == D_KEY)
		game->keys[D_INDEX] = false;
	update_player_position(game);
	return (NO_ERROR);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game);
	else if (keycode == RIGHT_KEY)
		game->keys[RIGHT_INDEX] = true;
	else if (keycode == LEFT_KEY)
		game->keys[LEFT_INDEX] = true;
	else if (keycode == W_KEY)
		game->keys[W_INDEX] = true;
	else if (keycode == S_KEY)
		game->keys[S_INDEX] = true;
	else if (keycode == A_KEY)
		game->keys[A_INDEX] = true;
	else if (keycode == D_KEY)
		game->keys[D_INDEX] = true;
	update_player_position(game);
	return (NO_ERROR);
}
