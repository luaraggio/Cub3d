/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:31:54 by lraggio           #+#    #+#             */
/*   Updated: 2025/02/21 14:18:27 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*

------------------------------- Raycasting ------------------------------
Setar valores para struct de raycasting
Calcular a direção do raio
Enxertar a posição do jogador no mapa
Calcular o tamanho do raio entre dois pontos (o ptempo que o raio leva para
atravessar um quadrado)


Calcular direção do raio direita, esqueda, cima e baixo
Calcular a distancia do raio até a próxima parede
Algoritmo de DDA (quando encontro uma parede)
Calcular a distância do jogador até a parede e corrigir a distorção da
perspectiva
Calcular a altura da parede

------------------------ Desenhar --------------------------------------
Desenhar linhas verticais
Desenhar minimapa

*/

int	init_raycasting_struct(t_game *game)
{
	t_raycast	*ray;

	ray = malloc(sizeof(t_raycast));
	if (!ray)
		return (ERROR);
	ray->pos_x = game->player->x;
	ray->pos_y = game->player->y;
	ray->dir_x = game->player->x_direction;
	ray->dir_y = game->player->y_direction;
	game->ray = ray;
	return (NO_ERROR);
}

void	render_game(t_game *game)
{
	init_raycasting_struct(game);
}