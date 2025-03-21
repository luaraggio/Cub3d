/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:29:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/21 14:01:32 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_texture_access(int *fd, char *texture, char *text_nickname);

void	set_texture(t_map *map, char *map_line, char *full_direction)
{
	int	j;

	j = 0;
	while (map_line[j] && map_line[j] == ' ')
		j++;
	j += 2;
	while (map_line[j] && map_line[j] == ' ')
		j++;
	if (my_strcmp(full_direction, "NO") == 0)
		map->textures->north_texture = my_strcdup(&(map_line[j]), ' ');
	else if (my_strcmp(full_direction, "SO") == 0)
		map->textures->south_texture = my_strcdup(&(map_line[j]), ' ');
	else if (my_strcmp(full_direction, "WE") == 0)
		map->textures->west_texture = my_strcdup(&(map_line[j]), ' ');
	else if (my_strcmp(full_direction, "EA") == 0)
		map->textures->east_texture = my_strcdup(&(map_line[j]), ' ');
}

int	open_texture(t_map *map)
{
	int	ret;

	ret = NO_ERROR;
	ret += check_texture_access(&(map->textures->fd_north_texture), \
		map->textures->north_texture, "north");
	ret += check_texture_access(&(map->textures->fd_south_texture), \
		map->textures->south_texture, "south");
	ret += check_texture_access(&(map->textures->fd_west_texture), \
		map->textures->west_texture, "west");
	ret += check_texture_access(&(map->textures->fd_east_texture), \
		map->textures->east_texture, "east");
	return (NO_ERROR);
}

static int	check_texture_access(int *fd, char *texture, char *text_nickname)
{
	*fd = open(texture, O_RDONLY);
	if (*fd == -1)
		return (my_printf_error(RED "Error\n" "Unable to open texture %s\n" \
			RESET, text_nickname));
	return (NO_ERROR);
}

void	create_texture_imgs(t_textures *textures, t_game *game)
{
	int	size;

	size = TEXTURE_SIZE;
	textures->north_texture_img->img = mlx_xpm_file_to_image(game->mlx, \
		textures->north_texture, &size, &size);
	textures->south_texture_img->img = mlx_xpm_file_to_image(game->mlx, \
		textures->south_texture, &size, &size);
	textures->west_texture_img->img = mlx_xpm_file_to_image(game->mlx, \
		textures->west_texture, &size, &size);
	textures->east_texture_img->img = mlx_xpm_file_to_image(game->mlx, \
		textures->east_texture, &size, &size);
	get_img_data_adds(textures);
}

void	get_img_data_adds(t_textures *textures)
{
	textures->north_texture_img->addr = \
		mlx_get_data_addr(textures->north_texture_img->img, \
		&(textures->north_texture_img->bpp), \
		&(textures->north_texture_img->size_line), \
		&(textures->north_texture_img->endian));
	textures->south_texture_img->addr = \
		mlx_get_data_addr(textures->south_texture_img->img, \
		&(textures->south_texture_img->bpp), \
		&(textures->south_texture_img->size_line), \
		&(textures->south_texture_img->endian));
	textures->west_texture_img->addr = \
		mlx_get_data_addr(textures->west_texture_img->img, \
		&(textures->west_texture_img->bpp), \
		&(textures->west_texture_img->size_line), \
		&(textures->west_texture_img->endian));
	textures->east_texture_img->addr = \
		mlx_get_data_addr(textures->east_texture_img->img, \
		&(textures->east_texture_img->bpp), \
		&(textures->east_texture_img->size_line), \
		&(textures->east_texture_img->endian));
}
