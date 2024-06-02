/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roherrer <roherrer@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:02:21 by roherrer          #+#    #+#             */
/*   Updated: 2024/06/02 18:02:26 by roherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	create_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		grid[i] = (int *) malloc(4 * 4);
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	input_clues(char *argv, int *clues)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (index < 31)
	{
		if (argv[index] <= '4' && argv[index] >= '1')
		{
			clues[j] = argv[index] - '0';
			j++;
		}
		else
			return (0);
		index += 2;
	}
	return (j == 16);
}
