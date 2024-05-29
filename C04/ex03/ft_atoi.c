/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:01:44 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 14:01:46 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	signo;
	int	result;

	index = 0;
	signo = 1;
	result = 0;
	while (str[index] == ' ')
	{
		index++;
	}
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			signo *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * signo);
}
/*
int	main(void)
{
	printf("%d", ft_atoi("            ---+--+1234ab567"));
}*/
