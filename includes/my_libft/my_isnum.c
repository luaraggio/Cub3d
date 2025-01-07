/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:00:36 by lpaixao-          #+#    #+#             */
/*   Updated: 2025/01/06 21:04:58 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_isnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	#include <stdio.h>
	#include <ctype.h>

	if (argc != 2)
	{
		printf("Favor digitar apenas um argumento \n");
		return (0);
	}
	int	i = 0;
	while (argv[1][i])
		i++;
	if (i > 1)
	{
		printf("Favor digitar apenas um caractere \n");
		return (0);
	}
	int	a;
	int	original;

	a = my_isalnum(argv[1][0]);
	original = isalnum(argv[1][0]);
	printf("Minha função: %i \n", a);
	if (a == 8)
		printf("O caractere digitado é ou um dígito (de 0 a 9) 
		ou uma letra \n");
	else
		printf("O caractere digitado não é nem um dígito (de 0 a 9) 
		nem uma letra \n");
	printf("Função original: %i \n", original);
	return (0);
}*/
