
#include "../../includes/cub3d.h"

void	select_texture(t_game *game, t_raycast *ray, t_image **texture)
{
	if (ray->side == VERTICAL_SIDE)
	{
		if (ray->dir_x > 0)
			*texture = game->map->textures->south_texture_img;
		else
			*texture = game->map->textures->north_texture_img;
	}
	else
	{
		if (ray->dir_y > 0)
			*texture = game->map->textures->west_texture_img;
		else
			*texture = game->map->textures->east_texture_img;
	}
}

int	calculate_tex_x(t_raycast *ray)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * (double)TEXTURE_SIZE);
	if ((ray->side == VERTICAL_SIDE && ray->dir_x > 0)
		|| (ray->side == HORIZONTAL_SIDE && ray->dir_y < 0))
		tex_x = TEXTURE_SIZE - tex_x - 1;
	return (tex_x);
}

int	calculate_tex_y(int y, t_raycast *ray)
{
	int	d;
	int	tex_y;

	d = y * 256 - W_HEIGHT * 128 + ray->line_height * 128;
	tex_y = ((d * TEXTURE_SIZE) / ray->line_height) / 256;
	return (tex_y);
}

void	draw_texture_column(t_game *game, t_image *texture, t_raycast *ray,
		int x)
{
	int	y;
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = calculate_tex_x(ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = calculate_tex_y(y, ray);
		if (tex_x >= 0 && tex_x < TEXTURE_SIZE && \
				tex_y >= 0 && tex_y < TEXTURE_SIZE)
		{
			color = *(unsigned int *)(texture->addr + \
						(tex_y * texture->size_line \
						+ tex_x * (texture->bpp / 8)));
			my_mlx_pixel_put(game->image, y, x, color);
		}
		y++;
	}
}

void	draw_vertical_lines(t_game *game, t_raycast *ray, int x)
{
	t_image	*texture;

	select_texture(game, ray, &texture);
	draw_texture_column(game, texture, ray, x);
}
