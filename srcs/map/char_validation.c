/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/08 16:49:47 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int valid_map_chars(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i])
    {
        if (line_is_direction(map->map[i]) == NO_ERROR)
            i++;
        else if (line_is_f_or_c(map->map[i]) == NO_ERROR)
            i++;
        else if (line_belongs_to_map(map->map[i]) == NO_ERROR)
            i++;
        else
        {
            my_printf_error(RED "Error\n" "Invalid characters have been found\n" RESET);
            return (ERROR);
        }
    }
    return (NO_ERROR);
}

int valid_player(t_map *map)
{
    int	i;
    int j;
    int player_count;
	
	i = 0;
    player_count = 0;
	while (line_belongs_to_map(map->map[i]) == ERROR)
        i++;
	while (map->map[i])
    {
//      printf("Map->map[%i]: %s\n", i, map->map[i]);
        j = 0;
        while (map->map[i][j])
        {
//            printf("Map->map[%i][%i]: %c\n", i, j, map->map[i][j]);
            if (is_player(map->map[i][j]) == NO_ERROR)
            {
//                printf("Player encontrado em map->map[%i][%i] %c\n", i, j, map->map[i][j]);
                player_count++;
            }
            j++;
        }
        i++;
    }
//    printf("Player count %i em map->map[%i][%i]\n", player_count, i, j);
    if (player_count != 1)
    {
        my_printf_error(RED "Error\n" "There must be one player, and only one, in the map\n" RESET);
        return (ERROR);
    }
    return (NO_ERROR);
}
