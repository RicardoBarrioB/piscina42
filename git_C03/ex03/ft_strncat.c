/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:20:55 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 12:20:58 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	index;
	unsigned int	cont;

	index = 0;
	cont = 0;
	while (dest[cont])
	{
		cont++;
	}
	while (src[index] && index <= nb - 1)
	{
		dest[cont + index] = src[index];
		index++;
	}
	return (dest);
}
/*
int	main(void)
{
	char dest[50] = "Hola, ";
	char src[10] = "adios.";
	ft_strncat(dest, src, 4);
	printf("%s", dest);
	return 0;
}*/
