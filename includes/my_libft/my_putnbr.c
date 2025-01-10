/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:48:39 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:48:40 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_own_putchar(char n);

int	my_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			count += write(1, "-", 1);
			n *= -1;
		}
		if (n > 9)
		{
			count += my_putnbr(n / 10);
		}
		count += my_own_putchar((n % 10) + '0');
	}
	return (count);
}

static int	my_own_putchar(char n)
{
	write(1, &n, 1);
	return (1);
}
