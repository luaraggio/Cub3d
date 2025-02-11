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

#include "../../includes/cub3d.h"

static void	print_walls(t_game *game, char **map_2d);
static void	print_player(t_game *game, char **map_2d);

/*
    POR ENQUANTO, SÓ PODE TESTAR COM UM MAPA COM UM FUBNDO QUE NÃO SEJA NEM BRANCO E NEM PRETO
    Vou ajustar isso ainda
*/

void    print_2dmap(t_game *game, char **map_2d)
{
   	print_walls(game, map_2d);
    print_player(game, map_2d);
}

static void	print_walls(t_game *game, char **map_2d)
{
    int i, j;
    int map_width = 0;
    int map_height = 0;
    int max_width = game->w_width / 3;  // Ajustar para um terço da tela, por exemplo
    int max_height = game->w_height / 3;
    double scale_x, scale_y, scale;

    // Calcular o tamanho do mapa
    while (map_2d[map_height])
        map_height++;
    while (map_2d[0][map_width])
        map_width++;

    // Calcular a proporção para ajuste
    scale_x = (double)max_width / map_width;
    scale_y = (double)max_height / map_height;
    scale = (scale_x < scale_y) ? scale_x : scale_y;

    // Desenhar o mapa escalado
    for (i = 0; i < map_height; i++)
    {
        for (j = 0; j < map_width; j++)
        {
            if (map_2d[i][j] == '1') // Supondo que '1' seja parede
            {
                int x = j * scale;
                int y = i * scale;
                int size = scale; // Tamanho da célula

                // Desenha um quadrado preenchido para representar a parede
                for (int dy = 0; dy < size; dy++)
                {
                    for (int dx = 0; dx < size; dx++)
                    {
                        my_mlx_pixel_put(game->image, x + dx, y + dy, 0x999999);
                    }
                }
            }
        }
    }
}

static void	print_player(t_game *game, char **map_2d)
{
    int map_width = 0, map_height = 0;
    int max_width = game->w_width / 3;
    int max_height = game->w_height / 3;
    double scale_x, scale_y, scale;
    
    while (map_2d[map_height])
        map_height++;
    while (map_2d[0][map_width])
        map_width++;

    scale_x = (double)max_width / map_width;
    scale_y = (double)max_height / map_height;
    scale = (scale_x < scale_y) ? scale_x : scale_y;

    // Converter posição do jogador para o novo tamanho
    int player_x = game->player->x * scale;
    int player_y = game->player->y * scale;
    int player_size = scale / 2;  // Ajustar o tamanho do player

    // Desenha o jogador como um pequeno quadrado
    for (int dy = -player_size; dy <= player_size; dy++)
    {
        for (int dx = -player_size; dx <= player_size; dx++)
        {
            my_mlx_pixel_put(game->image, player_x + dx, player_y + dy, 0x000000);
        }
    }
}

/*
static void	print_walls(t_game *game, char **map_2d)
{
    int	i;
	int	j;
	int	proportion;

	i = 0;
	j = 0;
	proportion = 10;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == 1)
				my_mlx_pixel_put(game->image, i, j, 999999);
			j++;
		}  
		i++;
	}
}

static void	print_player(t_game *game, char **map_2d)
{
	int	i;
	int	j;
	int	proportion;

	i = 0;
	j = 0;
	proportion = 10;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (i > (game->player->x - proportion) && i < (game->player->x + proportion) && j > (game->player->y - proportion) && j < (game->player->y + proportion))
				my_mlx_pixel_put(game->image, i, j, 000000);
			j++;
		}
		i++;
	}
}*/