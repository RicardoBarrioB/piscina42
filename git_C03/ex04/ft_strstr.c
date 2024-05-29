/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:25:33 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 12:25:36 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	index1;
	unsigned int	index2;

	index1 = 0;
	index2 = 0;
	while (str[index1] && to_find[index2])
	{
		if (str[index1] == to_find[index2])
			index2++;
		else if (index2 != 0)
		{
			index2 = 0;
			index1--;
		}
		index1++;
	}
	if (to_find[index2] == '\0')
		return (&str[index1 - index2]);
	else
		return (NULL);
}
/*
int	main(void)
{
	char src[50] = "Ho lad ds ad jh";
	char tofind[10] = "ad";
	printf("%s", ft_strstr(src, tofind));
	return 0;
}*/