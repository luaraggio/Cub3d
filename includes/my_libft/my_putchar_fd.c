
#include "libft.h"

int	my_putchar_fd(char c, int fd)
{
	return (write (fd, &c, 1));
}
