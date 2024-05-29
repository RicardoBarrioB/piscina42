/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:27:16 by rbarrio           #+#    #+#             */
/*   Updated: 2024/05/29 17:27:19 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, char *base, int len)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= len)
	{
		ft_putnbr(nb / len, base, len);
	}
	ft_putchar(base[nb % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	index;
	int	len;
	int	error;

	len = 0;
	index = -1;
	error = 0;
	while (base[len])
	{
		while (index >= 0)
		{
			if (base[len] == base[index])
				error = 1;
			else if (base[len] == '+' || base[len] == '-')
				error = 1;
			index--;
		}
		index = len;
		len++;
	}
	if (len != 0 && error == 0)
		ft_putnbr(nbr, base, len);
}
/*
int	main(void)
{
	ft_putnbr_base(-14654851, "0123456789ABCDEF");
}*/