/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:17:06 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/17 21:17:34 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_key(const char *key_name, const char *color)
{
	printf("A tecla " "%s%s" RESET " foi pressionada.\n", color, key_name);
}

int	press_key(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
	{
		print_key("ESQ", PINK);
		exit_game(game);
	}
	if (keycode == UP_KEY)
		print_key("seta para cima", PINK);
	if (keycode == DOWN_KEY)
		print_key("seta para baixo", PINK);
	if (keycode == RIGHT_KEY)
		print_key("seta para a direita", PINK);
	if (keycode == LEFT_KEY)
		print_key("seta para a esquerda", PINK);
	if (keycode == W_KEY)
		print_key("W", PINK);
	if (keycode == A_KEY)
		print_key("A", PINK);
	if (keycode == S_KEY)
		print_key("S", PINK);
	if (keycode == D_KEY)
		print_key("D", PINK);
	else
		printf(RED "Alguma outra tecla foi pressionada.\n" RESET);
	return (NO_ERROR);
}
