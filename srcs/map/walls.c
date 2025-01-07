/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:32:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/06 19:33:00 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	direction_ok(t_map *map, char *direction);
static int	check_texture(char *map_line, int j);

int	valid_walls(t_map *map)
{
	if (direction_ok(map, "NO") == ERROR)
		return (ERROR);
	if (direction_ok(map, "SO") == ERROR)
		return (ERROR);
	if (direction_ok(map, "WE") == ERROR)
		return (ERROR);
	if (direction_ok(map, "EA") == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	direction_ok(t_map *map, char *direction)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
//	printf("Vai checar a direção\n");
	while (map->map[i] && map->map[i][0] != '1')
	{
		j = 0;
//		printf("Linha %d: %s\n", i, map->map[i]);
		while (map->map[i][j] && map->map[i][j] != '1')
		{
			if (my_strncmp(&(map->map[i][j]), direction, 2) == 0)
			{
				flag++;
				if (check_texture(map->map[i], j + 2) == ERROR)
					return (ERROR);
				break ;
			}
			else if (map->map[i][j] != ' ')
				break ;
			j++;
		}
		i++;
	}
	if (flag != 1)
	{
		my_printf_error(RED "Error\n" "There must be one, and only one, %s\n" RESET, direction);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	check_texture(char *map_line, int j)
{
	(void)j;
	printf("Vai checar a textura %s\n", map_line);
	// 1- Arquivo existe?
	// 2- Tem permissão de leitura?
	//          Os 2 de cima descobrimos com open
	// 3- A extensão do arquivo está correta?
	return (NO_ERROR);
}