/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:52:16 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 12:52:20 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	cont;

	index = 0;
	cont = 0;
	while (dest[cont] && cont <= size - 1)
	{
		cont++;
	}
	while (src[index] && cont + index <= size - 1)
	{
		dest[cont + index] = src[index];
		index++;
	}
	if (cont + index < size)
		dest[cont + index] = '\0';
	else
		dest[size - 1] = '\0';
	return (cont + index);
}
/*
int	main(void)
{
	char dest[10] = "Hola, ";
	char src[10] = "ad";
	
	printf("%d", ft_strlcat(dest, src, 10));
	return 0;
}*/
