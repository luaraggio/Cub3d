/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:22:20 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/02 19:16:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_background(t_image *img, t_map *map);
//static void print_img_struct(t_image *img, char *name);

void	print_game(t_game *game)
{
	print_background(game->image, game->map);
	print_2dmap(game, game->map->map);
	mlx_put_image_to_window(game->mlx, game->win, game->image->img, 0, 0);
}

static void	print_background(t_image *img, t_map *map) // Mudar de printagem de pixels para printagem de retângulos
{
	int i;
	int j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			if (i < W_HEIGHT / 2)
				my_mlx_pixel_put(img, i, j, map->ceiling_color); // Cor do teto
			else
				my_mlx_pixel_put(img, i, j, map->floor_color); // Cor do chão
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_image *image, int i, int j, int color)
{
	char *dst;

	dst = image->addr + (i * image->size_line + j * (image->bpp / 8));
	*(unsigned int*)dst = color;
}
/*
static void print_img_struct(t_image *img, char *name)
{
	printf("Printing %s\n", name);
	printf("img_addr: %s\n", img->addr);
	printf("bpp: %d\n", img->bpp);
	printf("endian: %d\n", img->endian);
	printf("bits_per_pixel: %d\n", img->bits_per_pixel);
	printf("size_line: %d\n", img->size_line);
	printf("size_height: %d\n", img->size_height);
	printf("\n");
}
*/