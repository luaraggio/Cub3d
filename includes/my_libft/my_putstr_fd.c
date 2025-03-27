
#include "libft.h"

int	my_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
