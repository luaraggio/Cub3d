/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:56:27 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/08 16:56:28 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void malloc_map(t_map *map);

void    copy_map(t_map *map)
{
    int i;
    int j;
    int k;

    i = map->i_start;
    j = 0;
    k = 0;
    malloc_map(map);
    while (map->map_file[i])
    {
        j = 0;
        while (map->map_file[i][j])
        {
            map->map[k][j] = map->map_file[i][j];
            j++;
        }
        k++;
        i++;
    }
    print_matrix(map->map);
}

static void malloc_map(t_map *map)
{
    int i;
    int j;

    i = map->i_start;
    j = 0;
//    printf("total_i = %d\n", map->total_i);
//    printf("i_start = %d\n", map->i_start);
//    printf("Vai mallocar map->total_i - map->i_start + 2 = %d\n", map->total_i - map->i_start + 1);
    map->map = my_calloc(map->total_i - map->i_start + 2, sizeof(char **));
    while (map->map_file[i])
    {
        j = 0;
        while (map->map_file[i][j])
            j++;
//        printf("Em map[%i] vai malocar %i\n", i, j + 1);
        map->map[i] = my_calloc(j + 1, sizeof(char *));
        i++;
    }
//    printf("Mapa alocado. Falta copiar\n");
}