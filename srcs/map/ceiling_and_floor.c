/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:34:17 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/06 19:34:18 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rgb_is_valid(t_map *map, int i, int j);

int	valid_ceiling_and_floor(t_map *map)
{
	int	i;
	int	j;
	int	c_flag;
	int	f_flag;

	i = 0;
	c_flag = 0;
	f_flag = 0;
//	printf("Vai checar céu e chão\n");
	while (map->map[i] && line_belongs_to_map(map->map[i]) == ERROR)
	{
		j = 0;
//		printf("Linha %d: %s\n", i, map->map[i]);
		while (map->map[i][j] && line_belongs_to_map(map->map[i]) == ERROR)
		{
//			printf("map->map[%d][%d] = %c\n", i, j, map->map[i][j]);
			if (map->map[i][j] == 'C')
			{
//				printf("Entrou no if de C\n");
				c_flag++;
				if (rgb_is_valid(map, i, j++) == ERROR)
					return (ERROR);
			}
			else if (map->map[i][j] == 'F')
			{
//				printf("Entrou no if de F\n");
				f_flag++;
				if (rgb_is_valid(map, i, j++) == ERROR)
					return (ERROR);
			}
			else if (map->map[i][j] != ' ')
				break ;
			j++;
		}
		i++;
	}
//	printf("c_flag = %i e f_flag = %i\n", c_flag, f_flag);
	if (c_flag == 0 || f_flag == 0)
	{
		my_printf_error(RED "Error\n" "Ceiling or floor not found\n" RESET);
		return (ERROR);
	}
	else if (c_flag > 1 || f_flag > 1)
	{
		my_printf_error(RED "Error\n" "There can be only one floor and only one ceiling\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}

static int	rgb_is_valid(t_map *map, int i, int j)
{
	int		num;
	int		rgb_size;
	char	*str_n;
	int		line_size;

	num = 0;
	rgb_size = 0;
	str_n = NULL;
	line_size = my_strlen(map->map[i]);
	while (j <= line_size && map->map[i][j])
	{
//		printf("No loop: map->map[%d][%d] = %c\n", i, j, map->map[i][j]);
		if ((my_isnum(map->map[i][j]) != 0 || map->map[i][j] == '-' || map->map[i][j] == '+') && rgb_size < 3)
		{
//			printf("No if de é número: map->map[%d] = %s\n", i, map->map[i]);
//			printf("No if de é número: map->map[%d][%d] = %c\n", i, j, map->map[i][j]);
			rgb_size++;
			if (rgb_size < 3 && map->map[i][j + 1] == ',')
				str_n = my_strcdup(&map->map[i][j], ',');
			else
				str_n = my_strcdup(&map->map[i][j], '\0');
			num = atoi(str_n);
//			printf("strn = %s\n", str_n);
//			printf("my_strlen(str_n) = %ld\n", my_strlen(str_n));
			j = j + my_strlen(str_n);
			free(str_n);
			str_n = NULL;
//			printf("Num = %d\n", num);
//			printf("Deposid e ajustar j = %d, em %c\n", j, map->map[i][j]);
//			printf("No loop: rgb_size = %d\n", rgb_size);
			if (num < 0 || num > 255)
			{
				my_printf_error(RED "Error\n" "Invalid RGB value\n" RESET);
				return (ERROR);
			}
		}
		j++;
	}
//	printf("Fora do loop: rgb_size = %d\n", rgb_size);
	if (rgb_size != 3)
	{
		my_printf_error(RED "Error\n" "Invalid RGB format\n" RESET);
		return (ERROR);
	}
	return (NO_ERROR);
}
