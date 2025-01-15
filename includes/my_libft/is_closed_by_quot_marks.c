/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed_by_quot_marks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:47:14 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:47:16 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_closed_by_quot_marks(char *str)
{
	int	i;

	i = my_strlen(str) - 1;
	if (str[0] == 34 && str[i] == 34)
		return (1);
	else if (str[0] == 39 && str[i] == 39)
		return (1);
	return (0);
}
