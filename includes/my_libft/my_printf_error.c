/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:43:04 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/03/21 14:41:59 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ptr(unsigned long int ptr)
{
	if (ptr == 0)
		return (my_putstr_fd("(nil)", 2));
	return ((my_putstr_fd("0x", 2) + my_putnbr_base_fd(ptr, 16, 'p', 2)));
}

static int	type_verification(va_list *args, char c)
{
	if (c == 'c')
		return (my_putchar_fd(va_arg(*args, int), 2));
	else if (c == 's')
		return (my_putstr_fd(va_arg(*args, char *), 2));
	else if (c == 'p')
		return (check_ptr(va_arg(*args, unsigned long int)));
	else if (c == 'd' || c == 'i')
		return (my_putnbr_fd(va_arg(*args, int), 2));
	else if (c == 'u')
		return (my_putnbr_base_fd(va_arg(*args, unsigned int), 10, 'c', 2));
	else if (c == 'x')
		return (my_putnbr_base_fd(va_arg(*args, unsigned int), 16, c, 2));
	else if (c == 'X')
		return (my_putnbr_base_fd(va_arg(*args, unsigned int), 16, c, 2));
	else if (c == '%')
		return (my_putchar_fd('%', 2));
	return (0);
}

int	my_printf_error(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(2, &str[i], 1);
		else if (str[i] == '%' && str[i + 1] == ' ' && str[i + 2] == '%')
		{
			count += write(2, &str[i + 2], 1);
			i = i + 2;
		}
		else
			count += type_verification(&args, str[i++ + 1]);
		i++;
	}
	va_end(args);
	return (count);
}
