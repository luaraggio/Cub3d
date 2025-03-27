
#include "libft.h"

void	my_clean_int_vect(int **vect)
{
	int	i;

	i = 0;
	while (vect[i])
		i++;
	while (i >= 0)
	{
		free(vect[i]);
		vect[i] = NULL;
		i--;
	}
	free(vect);
	vect = NULL;
}
