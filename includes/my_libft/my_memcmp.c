/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:48:03 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:48:05 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;
	unsigned int	cmp;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	cmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (count <= (n - 1))
	{
		cmp = str1[count] - str2[count];
		if (str1[count] != str2[count])
			return (cmp);
		count++;
	}
	return (cmp);
}
