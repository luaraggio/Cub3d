/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:47:15 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/02/05 15:47:18 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	rgb_to_hexa(char *str);
static int	get_decimal(char *str);
static void	dec_to_hex(int n, char *str);

int	get_color(t_map *map, char ref)
{
	int		i;
	int		color;

	i = 0;
	color = OFF;
	while (map->map[i])
	{
		if (map->map[i][0] == ref)
		{
			i++;
			while (map->map[i][0] == ' ')
				i++;
			color = rgb_to_hexa(my_substr(map->map[i], 1, my_strlen(map->map[i])));
		}
		i++;
	}
	return (color);
}

static int	rgb_to_hexa(char *str)
{
	char	*str_color;
	char	*str_start_point;
	int		color;
	int		decimal;

	color = OFF;
	str_start_point = str;
	str_color = malloc((7 + 1) * sizeof(char));
	str_color[0] = '#';
	str_color[7] = '\0';
	decimal = get_decimal(my_substr(str, 0, 2));
	dec_to_hex(decimal, &(str_color[1]));
	printf("str_color: %s\n", str_color);
	printf("str: %s\n", str);
	str += 4; // Não vai ser sempre o mesmo tamanho
	decimal = get_decimal(my_substr(str, 0, 2));
	dec_to_hex(decimal, &(str_color[3]));
	printf("st_color: %s\n", str_color);
	printf("str: %s\n", str);
	str += 4; // Não vai ser sempre o mesmo tamanho
	decimal = get_decimal(my_substr(str, 0, 2));
	dec_to_hex(decimal, &(str_color[5]));
	printf("str_color: %s\n", str_color);
	printf("str: %s\n", str);
	free(str_start_point);
	color = atoi(str_color);
	free(str_color);
	printf("collor: %i\n", color);
	return (color);
}

static int	get_decimal(char *str)
{
	int		decimal;

	decimal = atoi(str);
	free(str);
	return (decimal);
}

static void	dec_to_hex(int n, char *str)
{
	if (n >= 16)
		dec_to_hex(n / 16, str);
	str[n % 16] = "0123456789ABCDEF"[n % 16];
}