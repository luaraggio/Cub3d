/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:53:17 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/11 11:53:18 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	print_minigame(t_game *game, t_map2d *map_2d);
static void    found_wall(t_game *game, t_map2d *map_2d, int i, int j);
static int get_opposite_color(int color);
static void draw_player(t_game *game, t_map2d *map2d);
static void draw_line_to_wall(t_game *game, t_map2d *map2d);
//static void    print_map2d_struct(t_map2d *map2d);

void    print_2dmap(t_game *game, char **map_2d, t_player *player)
{
    (void)player;
    t_map2d map2d;
    double scale_x;
    double scale_y;

    my_bzero(&map2d, sizeof(t_map2d));
    map2d.map_2d = map_2d;
    map2d.max_width = W_WIDTH / 3;
    map2d.max_height = W_HEIGHT / 3;
    map2d.player_color = get_opposite_color(game->map->ceiling_color - 0x202020);
    map2d.wall_color = get_opposite_color(game->map->ceiling_color);

    map2d.map_height = 0;
    while (map_2d[map2d.map_height])
    {
        int current_width = my_strlen(map_2d[map2d.map_height]);
        if (current_width > map2d.map_width)
            map2d.map_width = current_width;
        map2d.map_height++;
    }

    scale_x = (double)map2d.max_width / map2d.map_width;
    scale_y = (double)map2d.max_height / map2d.map_height;
    map2d.scale = fmin(scale_x, scale_y);
    print_minigame(game, &map2d);
}

static void	print_minigame(t_game *game, t_map2d *map_2d)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < map_2d->map_height)
    {
        j = 0;
        while (j < map_2d->map_width)
        {
            if (map_2d->map_2d[i][j] == '1')
                found_wall(game, map_2d, i, j);
            j++;
        }
        i++;
    }
    draw_player(game, map_2d);
    draw_line_to_wall(game, map_2d);
}

static void    found_wall(t_game *game, t_map2d *map_2d, int i, int j)
{
    int dy;
    int dx;
    int x;
    int y;

    dy = 0;
    dx = 0;
    x = j * map_2d->scale;
    y = i * map_2d->scale;
    while (dy < map_2d->scale)
    {
        dx = 0;
        while (dx < map_2d->scale)
        {
            my_mlx_pixel_put(game->image, x + dx, y + dy, map_2d->wall_color);
            dx++;
        }
        dy++;
    }
}

static int get_opposite_color(int color)
{
    int r;
    int g;
    int b;
    int new_color;

    r = 0xFF - ((color >> 16) & 0xFF);
    g = 0xFF - ((color >> 8) & 0xFF);
    b = 0xFF - (color & 0xFF);
    new_color = (r << 16) | (g << 8) | b;
    return new_color;
}

static void draw_player(t_game *game, t_map2d *map2d)
{
    int size;
    int i;
    int j;
    float player_x = game->player->x + 0.5;
    float player_y = game->player->y + 0.5;

    size = 5; // Define o tamanho do jogador no minimapa
    i = -size;
    while (i <= size)
    {
        j = -size;
        while (j <= size)
        {
            my_mlx_pixel_put(
                game->image, 
                (int)(player_x * map2d->scale) + j,
                (int)(player_y * map2d->scale) + i,
                0xFF0000
            );
            j++;
        }
        i++;
    }
}

static void draw_line_to_wall(t_game *game, t_map2d *map2d)
{
    double x;
    double y;
    double x_dir;
    double y_dir;

    x = (game->player->x + 0.5) * map2d->scale;
    y = (game->player->y + 0.5) * map2d->scale;
    x_dir = game->player->x_direction * map2d->scale;
    y_dir = game->player->y_direction * map2d->scale;
    while (map2d->map_2d[(int)(y / map2d->scale)][(int)(x / map2d->scale)] != '1')
    {
        my_mlx_pixel_put(game->image, (int)x, (int)y, 0xFFFFFF);
        x += x_dir * 0.1;
        y += y_dir * 0.1;
    }
}

/*
static void    print_map2d_struct(t_map2d *map2d)
{
    printf("map2d.map_height = %d\n", map2d->map_height);
    printf("map2d.map_width = %d\n", map2d->map_width);
    printf("map2d.scale = %f\n", map2d->scale);
    printf("map2d.max_height = %f\n", map2d->max_height);
    printf("map2d.max_width = %f\n", map2d->max_width);
    printf("map2d.player_x = %f\n", map2d->player_x);
    printf("map2d.player_y = %f\n", map2d->player_y);
    printf("map2d.player_size = %f\n", map2d->player_size);
}*/