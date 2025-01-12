/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:48:05 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/12 11:48:08 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**my_copy_matrix(char **matrix)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
		i++;
	copy = (char **)my_calloc(i + 1, sizeof(char *));
	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
			j++;
		copy[i] = (char *)my_calloc(j + 1, sizeof(char));
		j = 0;
		while (matrix[i][j])
		{
			copy[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}
