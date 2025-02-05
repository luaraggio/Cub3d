/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:10:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/01 17:30:05 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_map(t_map *map)
{
	my_clean_vect(map->map);
	free(map->north_texture);
	free(map->south_texture);
	free(map->west_texture);
	free(map->east_texture);
	close_texture_fds(map);
}

void	close_texture_fds(t_map *map)
{
	close(map->fd_north_texture);
	close(map->fd_south_texture);
	close(map->fd_west_texture);
	close(map->fd_east_texture);
}
