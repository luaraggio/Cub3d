
#include "../../includes/cub3d_bonus.h"

int	line_belongs_to_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != '\n' || line[i] != '\0')
			&& character_belongs_to_map(line[i], line[i + 1]) == ERROR)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	line_is_direction(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (my_strncmp(&(line[j]), "NO", 2) == 0)
		return (NO_ERROR);
	else if (my_strncmp(&(line[j]), "SO", 2) == 0)
		return (NO_ERROR);
	else if (my_strncmp(&(line[j]), "EA", 2) == 0)
		return (NO_ERROR);
	else if (my_strncmp(&(line[j]), "WE", 2) == 0)
		return (NO_ERROR);
	else
		return (ERROR);
}

int	line_is_f_or_c(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (line[j] == 'C')
		return (NO_ERROR);
	else if (line[j] == 'F')
		return (NO_ERROR);
	return (ERROR);
}
