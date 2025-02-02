/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:22:20 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/02 15:22:23 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_background(t_game *game, t_image *img);
//static void	fill_rectangle(t_game *game, t_image *img, int width, int height, int color);
//static void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
static void print_img_struct(t_image *img, char *name);

void	print_game(t_game *game, t_map *map)
{
	(void)map;
	t_image	*img_floor;
	t_image	*img_ceiling;

	img_ceiling = (t_image *)malloc(sizeof(t_image));
	img_floor = (t_image *)malloc(sizeof(t_image));
	my_bzero(img_floor, sizeof(t_image));
	my_bzero(img_floor, sizeof(t_image));
	game->images->rectangle_ceiling = img_ceiling;
	game->images->rectangle_floor = img_floor;
	print_background(game, img_floor);
	print_background(game, img_ceiling);
	
}

static void	print_background(t_game *game, t_image *img) // Mudar de printagem de pixels para printagem de retângulos
{
	img->size_line = W_WIDTH;
	img->size_height = W_HEIGHT / 2;
	img->img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT / 2);
	img->addr = mlx_get_data_addr(img, &(img->bits_per_pixel), &(img->size_line), &(img->endian));
	print_img_struct(img, "img");
//	fill_rectangle(game, img, W_WIDTH, W_HEIGHT / 2, 0x00F00000);
//	mlx_put_image_to_window(game->mlx, game->win, img, 0, 0);
}

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
/*
static void	fill_rectangle(t_game *game, t_image *img, int width, int height, int color)
{
	(void)game;
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			//my_mlx_pixel_put(img, j, i, color);
			printf("Oie!\n");
			j++;
		}
		i++;
	}
}

static void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;
	(void)color;

	dst = image->addr + (y * image->size_line + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}*/