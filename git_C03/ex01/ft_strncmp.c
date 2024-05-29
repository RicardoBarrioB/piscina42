/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:46:42 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/28 18:46:45 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] == s2[index] && index < n - 1)
	{
		index++;
	}
	if (index == n)
		return (0);
	return (s1[index] - s2[index]);
}
/*
int	main(void)
{
	printf("%d", ft_strncmp("Hola", "Hola", 10));
}*/
