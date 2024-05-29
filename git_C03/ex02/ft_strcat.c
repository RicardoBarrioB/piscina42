/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:00:53 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 12:00:55 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	cont;

	index = 0;
	cont = 0;
	while (dest[cont])
	{
		cont++;
	}
	while (src[index])
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
	ft_strcat(dest, src);
	printf("%s", dest);
	return 0;
}*/
