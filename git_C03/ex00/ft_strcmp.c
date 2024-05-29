/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:42:17 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/28 17:42:19 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] != '\0')
	{
		index++;
	}
	return (s1[index] - s2[index]);
}
/*
int	main(void)
{
	printf("%d", ft_strcmp("Hola", "Hola"));
}*/