
#include "../../includes/cub3d_bonus.h"

static void	print_background(t_image *img, t_map *map);

void	print_game(t_game *game)
{
	print_background(game->image, game->map);
	raycasting(game, game->ray);
	print_2dmap(game, game->map->map, game->player);
	mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
}

static void	print_background(t_image *img, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			if (i < W_HEIGHT / 2)
				my_mlx_pixel_put(img, i, j, map->ceiling_color);
			else
				my_mlx_pixel_put(img, i, j, map->floor_color);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_image *image, int i, int j, int color)
{
	char	*dst;

	dst = image->addr + (i * image->size_line + j * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

void	create_general_img(void *mlx, t_image *img)
{
	img->size_line = W_WIDTH;
	img->size_height = W_HEIGHT;
	img->img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_line),
			&(img->endian));
}
