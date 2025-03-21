/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:29:02 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/15 18:08:44 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_texture(t_map *map, char *map_line, char *direction)
{
	int	j;

	j = 2;
//	printf("EM SET TEXTURE: \nDirection = %s\nmap_line[%i] = %c\n", direction, j, map_line[j]);
	while (map_line[j] && map_line[j] == ' ')
		j++;
//	printf("EM SET TEXTURE: depois do while com map_line[%i] = %c\n", j, map_line[j]);
	if (my_strcmp(direction, "NO") == 0)
		map->textures->north_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "SO") == 0)
		map->textures->south_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "WE") == 0)
		map->textures->west_texture = my_strdup(&(map_line[j]));
	else if (my_strcmp(direction, "EA") == 0)
		map->textures->east_texture = my_strdup(&(map_line[j]));
//	printf("NO = %s\n", map->textures->north_texture);
//	printf("SO = %s\n", map->textures->south_texture);
//	printf("WE = %s\n", map->textures->west_texture);
//	printf("EA = %s\n", map->textures->east_texture);
}

int	open_texture(t_map *map)
{
	map->textures->fd_north_texture = open(map->textures->north_texture, O_RDONLY);
	if (map->textures->fd_north_texture == -1)
		return (my_printf_error(RED "Error\n" "Unable to open texture north\n" RESET));
	map->textures->fd_south_texture = open(map->textures->south_texture, O_RDONLY);
	if (map->textures->fd_south_texture == -1)
	{
		return (my_printf_error(RED "Error\n" "Unable to open texture south\n" RESET));
	}
	map->textures->fd_west_texture = open(map->textures->west_texture, O_RDONLY);
	if (map->textures->fd_west_texture == -1)
	{
		return (my_printf_error(RED "Error\n" "Unable to open texture west\n" RESET));
	}
//	printf("Vai abrir a textura leste, %s\n", map->textures->east_texture);
	map->textures->fd_east_texture = open(map->textures->east_texture, O_RDONLY);
//	printf("map->fd_east_texture == %d\n", map->fd_east_texture);
	if (map->textures->fd_east_texture == -1)
	{
		return (my_printf_error(RED "Error\n" "Unable to open texture east\n" RESET));
	}
	return (NO_ERROR);
}

int	check_textures_extension(t_map *map)
{
	int	size;
	int	ret;
	
	ret = NO_ERROR;
	size = my_strlen(map->textures->north_texture);
	if (map->textures->north_texture[size - 4] != '.' || map->textures->north_texture[size - 3] != 'x' || map->textures->north_texture[size - 2] != 'p' || map->textures->north_texture[size - 1] != 'm')
		ret = my_printf_error(RED "Error\n" "Invalid file extension for north texture\n" RESET);
	size = my_strlen(map->textures->south_texture);
	if (map->textures->south_texture[size - 4] != '.' || map->textures->south_texture[size - 3] != 'x' || map->textures->south_texture[size - 2] != 'p' || map->textures->south_texture[size - 1] != 'm')
		ret = my_printf_error(RED "Error\n" "Invalid file extension for south texture\n" RESET);
	size = my_strlen(map->textures->west_texture);
	if (map->textures->west_texture[size - 4] != '.' || map->textures->west_texture[size - 3] != 'x' || map->textures->west_texture[size - 2] != 'p' || map->textures->west_texture[size - 1] != 'm')
		ret = my_printf_error(RED "Error\n" "Invalid file extension for west texture\n" RESET);
	size = my_strlen(map->textures->east_texture);
	if (map->textures->east_texture[size - 4] != '.' || map->textures->east_texture[size - 3] != 'x' || map->textures->east_texture[size - 2] != 'p' || map->textures->east_texture[size - 1] != 'm')
		ret = my_printf_error(RED "Error\n" "Invalid file extension for east texture\n" RESET);
	if (ret != NO_ERROR)
	{
		close_texture_fds(map);
		return (ERROR);
	}
	return (NO_ERROR);
}

void	create_texture_imgs(t_textures *textures, t_game *game)
{
	int	size;
	
	size = TEXTURE_SIZE;
	textures->north_texture_img->img = mlx_xpm_file_to_image(game->mlx, textures->north_texture, &size, &size);
	textures->south_texture_img->img = mlx_xpm_file_to_image(game->mlx, textures->south_texture, &size, &size);
	textures->west_texture_img->img = mlx_xpm_file_to_image(game->mlx, textures->west_texture, &size, &size);
	textures->east_texture_img->img = mlx_xpm_file_to_image(game->mlx, textures->east_texture, &size, &size);
	textures->north_texture_img->addr = mlx_get_data_addr(textures->north_texture_img->img, &(textures->north_texture_img->bpp), &(textures->north_texture_img->size_line), &(textures->north_texture_img->endian));
	textures->south_texture_img->addr = mlx_get_data_addr(textures->south_texture_img->img, &(textures->south_texture_img->bpp), &(textures->south_texture_img->size_line), &(textures->south_texture_img->endian));
	textures->west_texture_img->addr = mlx_get_data_addr(textures->west_texture_img->img, &(textures->west_texture_img->bpp), &(textures->west_texture_img->size_line), &(textures->west_texture_img->endian));
	textures->east_texture_img->addr = mlx_get_data_addr(textures->east_texture_img->img, &(textures->east_texture_img->bpp), &(textures->east_texture_img->size_line), &(textures->east_texture_img->endian));
}