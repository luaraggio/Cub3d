
#include "../../includes/cub3d.h"

void	rotate_player_to_right(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	player->x_direction = player->x_direction * cos(ROTATION_SPEED)
		- player->y_direction * sin(ROTATION_SPEED);
	player->y_direction = old_x * sin(ROTATION_SPEED) + player->y_direction
		* cos(ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(ROTATION_SPEED) - player->plane_y
		* sin(ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(ROTATION_SPEED) + player->plane_y
		* cos(ROTATION_SPEED);
}

void	rotate_player_to_left(t_player *player)
{
	double	old_x;
	double	old_plane_x;

	old_x = player->x_direction;
	old_plane_x = player->plane_x;
	player->x_direction = old_x * cos(-ROTATION_SPEED) - player->y_direction
		* sin(-ROTATION_SPEED);
	player->y_direction = old_x * sin(-ROTATION_SPEED) + player->y_direction
		* cos(-ROTATION_SPEED);
	player->plane_x = player->plane_x * cos(-ROTATION_SPEED) - player->plane_y
		* sin(-ROTATION_SPEED);
	player->plane_y = old_plane_x * sin(-ROTATION_SPEED) + player->plane_y
		* cos(-ROTATION_SPEED);
}
