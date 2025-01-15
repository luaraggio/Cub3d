/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:49:25 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:49:27 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strldup(const char *s, int i)
{
	char	*dest;

	dest = (char *)malloc(i + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	my_strlcpy(dest, s, i + 1);
	return (dest);
}

/*
#include <stdio.h>

int	main()
{
	#include <string.h>

	const char	str[] = "Abacaxi";
	char	*dest2;

	dest2 = my_strcdup(str, 'c');
	printf("Minha pŕopria função strcdup(): %s\n", dest2);
	free(dest2);
	return (0);
}*/
