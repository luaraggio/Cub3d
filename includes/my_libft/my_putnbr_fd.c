/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:48:36 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:48:37 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_own_putchar(char n, int fd);

int	my_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			count += write(fd, "-", 1);
			my_putnbr_fd((n = -n), fd);
		}
		else if (n > 9)
		{
			count += my_putnbr_fd((n / 10), fd);
			count += my_putnbr_fd((n % 10), fd);
		}
		else
			count += my_own_putchar((n + '0'), fd);
	}
	return (count);
}

static int	my_own_putchar(char n, int fd)
{
	return (write(fd, &n, 1));
}
/*
#include <limits.h>
#include <stdio.h>
int		main()
{
	my_putnbr_fd(6, 1);
}*/
