/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_clean_int_vect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao <lpaixao-@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:47:34 by lpaixao           #+#    #+#             */
/*   Updated: 2025/01/09 22:47:36 by lpaixao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
