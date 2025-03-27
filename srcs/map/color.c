
#include "../../includes/cub3d.h"

static unsigned int	rgb_to_hexa(char *str);

unsigned int	get_color(t_map *map, char ref)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	j = 0;
	color = OFF;
	while (map->map_file[i])
	{
		if (map->map_file[i][j] == ref)
		{
			j++;
			while (map->map_file[i][j] == ' ')
				j++;
			color = rgb_to_hexa(my_substr(&(map->map_file[i][j]), 0,
						my_strlen(&(map->map_file[i][j]))));
		}
		i++;
	}
	return (color);
}

char	*dec_to_hex(int n)
{
	char	*str;
	int		i;

	i = 1;
	str = my_calloc(3, sizeof(char));
	str[2] = '\0';
	while (i >= 0)
	{
		str[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}

int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'A' && c <= 'F')
	{
		return (10 + (c - 'A'));
	}
	else if (c >= 'a' && c <= 'f')
	{
		return (10 + (c - 'a'));
	}
	return (-1);
}

unsigned int	hex_string_to_int(const char *hex)
{
	unsigned int	result;
	int				value;

	result = 0;
	while (*hex)
	{
		value = hex_char_to_int(*hex);
		result = result * 16 + value;
		hex++;
	}
	return (result);
}

static unsigned int	rgb_to_hexa(char *str)
{
	char			*str_hex_color;
	char			**str_rgb;
	int				rgb[3];
	int				i;
	unsigned int	color;

	i = 0;
	color = OFF;
	str_rgb = my_split(str, ',');
	while (i < 3)
	{
		rgb[i] = my_atoi(str_rgb[i]);
		i++;
	}
	my_clean_vect(str_rgb);
	str_hex_color = my_calloc((7 + 1), sizeof(char));
	i = 0;
	while (i < 3)
	{
		str_hex_color = my_strjoin_cleaning(str_hex_color, dec_to_hex(rgb[i]));
		i++;
	}
	color = hex_string_to_int(str_hex_color);
	return (free(str), free(str_hex_color), color);
}
