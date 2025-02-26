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
//static void print_int_map(t_map *map);

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
//        printf("i = %d\n", i);
        j = 0;
        while (map->map_file[i][j])
        {
//            printf("j = %d\n", j);
            map->map[k][j] = map->map_file[i][j];
            j++;
        }
        k++;
        i++;
    }
//    print_matrix(map->map);
}

static void malloc_map(t_map *map)
{
    int i;
    int k;
    int j;

    i = map->i_start;
    k = 0;
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
//        printf("Em map->map[%i] vai malocar %i\n", i, j + 1);
        map->map[k] = my_calloc(j + 1, sizeof(char *));
        i++;
        k++;
    }
//    printf("Mapa alocado. Falta copiar\n");
}

void    map_to_int(t_map *map)
{
    map->map_int = my_calloc(map->total_i - map->i_start + 2, sizeof(int **));
    int i = 0;
    int j = 0;

    while (map->map[i])
    {
        map->map_int[i] = my_calloc(my_strlen(map->map[i]) + 1, sizeof(int *));
        j = 0;
        while (map->map[i][j])
        {
//            printf("map->map[%d][%d] = %c\n", i, j, map->map[i][j]);
            if (map->map[i][j] == '1')
                map->map_int[i][j] = 1;
            else
                map->map_int[i][j] = 0;
//            printf("map->map_int[%d][%d] = %d\n", i, j, map->map_int[i][j]);
            j++;
        }
        i++;
    }
}
/*
static void print_int_map(t_map *map)
{
    int i = 0;
    int j = 0;

    while (i < map->total_i - map->i_start + 1)
    {
        j = 0;
        while (j < (int)my_strlen(map->map[i]))
        {
            printf("%d", map->map_int[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}*/