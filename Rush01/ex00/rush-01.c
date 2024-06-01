/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roherrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:26:07 by roherrer          #+#    #+#             */
/*   Updated: 2024/06/01 14:00:56 by roherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c, int n)
{
	while (n > 0)
	{
		write(1, c, 1);
		c++;
		n--;
	}
}

void	create_grid(int **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < 4)
	{
		grid[i] = (int *) malloc(4 * 4);
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void copy_array(int *box, int *copy, int i)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if(index == i)
		{
			copy[index] = 0;
			index++;
		}
		copy[index] = box[index];
		index++;
	}
}

int	derecha(int *grid, int right)
{
	int count;
	int j;

	count = 1;
	j = 3;
	while (grid[j] < grid[j - 1])
	{
		count++;
		j--;			
	}
	if(count == right)
		return (1);
	return (0);
}

int	izda(int *grid, int left, int right, int *copy)
{
	int count;
	int j;

	count = 1;
	j = 0;
	while (grid[j] < grid[j + 1] && j <= 2)
	{
		j++;
		count++; 
	}
	if(count <= left)
	{
		if(filas(grid, left, right, copy) == 1)
		{
			free(copy);
			return (1);
		}
	}
	else
	{
		free(copy);
		return(0);
	}
}

int	filas(int *grid, int left, int right, int *box)
{
	int index;
	int *copy;

	index = 3;
	copy = (int *) malloc(4 * 4);
	while(index >= 0)
	{
		if(box[index] != 0)
		{
			*grid = box[index];
			copy_array(box, copy, index);
			grid++;
			izda(grid, left, right, copy);
			grid--;
		}
		else if (box[index] == 0 && index == 0)
		{
			free(copy);
			return(derecha(grid, right));
		}
		index--;
	}
	//free(copy);
	return (0);
}

void	put_box(int **grid, int *left, int *right, int *box)
{
	int i;

	i = 0;
	while (i < 4)
	{
		filas(grid[i], left[i], right[i], box);
		i++;
	}
}

int column(int *grid, int *column, int up, int down)
{
	int count;
	int j;

	count = 1;
	j = 3;
	while (grid[j] < grid[j - 1])
	{
		count++;
		j--;			
	}
	if(count == down)
		count = 1;
		j = 0;
		while (grid[j] < grid[j + 1])
		{
			count++;
			j++;			
		}
		if(count == up)
			return (1);
	return (0);
}

int	columnas(int **grid, int *up, int *down)
{
	int count;
	int i;
	int j;
	int *copy_column;

	i = 0;
	count = 0;
	copy_column = (int *) malloc(4 * 4);
	while (i < 4)
	{
		j = 0;
		while (i < 4)
		{
			copy_column = grid[i][j];
			j++;
		}
		if(column(grid[i], copy_column, up[i], down[i]) == 1)
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void print_all(int **grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar('0' + grid[i][j], 1);
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int index;
/*	int **grid;
	int *box = {1, 2, 3, 4};
	int *up;
	int *down;
	int *left;
	int *right;

	index = 0;
	up = (int *) malloc(4 * 4);
	down = (int *) malloc(4 * 4);
	left = (int *) malloc(4 * 4);
	right = (int *) malloc(4 * 4);
*/
	int **grid = (int **) malloc(4 * 4);
	int box[4] = {1, 2, 3, 4};
	int up[4], down[4], left[4], right[4];
	if (argc == 17)
	{
		while (index < argc -1)
		{
			if(index < 4)
				up[index] = argv[index + 1] - '0';
			else if (index < 8)
				down[index - 4] = argv[index + 1] - '0';
			else if (index < 12)
				left[index - 8] = argv[index + 1] - '0';
			else
				right[index - 12] = argv[index + 1] - '0';
			index++;
		}
		create_grid(grid);
		put_box(grid, left, right, box);
		columnas(grid, up, down);

		print_all(grid);
	}
	else 
		ft_putchar("Error", 5);
}
