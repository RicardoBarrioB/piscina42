/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roherrer <roherrer@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:58:57 by roherrer          #+#    #+#             */
/*   Updated: 2024/06/02 17:59:05 by roherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	num_valid(int **grid, int row, int col, int num)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		if (grid[row][index] == num || grid[index][col] == num)
			return (0);
		index++;
	}
	return (1);
}

int	count_box(int *array)
{
	int	count;
	int	index;
	int	max_box;

	count = 0;
	index = 0;
	max_box = 0;
	while (index < 4)
	{
		if (array[index] > max_box)
		{
			max_box = array[index];
			count++;
		}
		index++;
	}
	return (count);
}

int	check_rows(int **grid, int *clues, int *array, int col)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		array[row] = grid[row][col];
		row++;
	}
	if (count_box(array) != clues[col])
	{
		free(array);
		return (0);
	}
	row = 0;
	while (row < 4)
	{
		array[row] = grid[3 - row][col];
		row++;
	}
	if (count_box(array) != clues[4 + col])
	{
		free(array);
		return (0);
	}
	return (1);
}

int	check_cols(int **grid, int *clues, int *array, int row)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		array[col] = grid[row][col];
		col++;
	}
	if (count_box(array) != clues[8 + row])
		return (0);
	col = 0;
	while (col < 4)
	{
		array[col] = grid[row][3 - col];
		col++;
	}
	if (count_box(array) != clues[12 + row])
		return (0);
	return (1);
}

int	check_box(int **grid, int *clues)
{
	int	*array;
	int	index;

	array = (int *) malloc (4 * 4);
	index = 0;
	while (index < 4)
	{
		if (!check_rows(grid, clues, array, index))
			return (0);
		index++;
	}
	index = 0;
	while (index < 4)
	{
		if (!check_cols(grid, clues, array, index))
			return (0);
		index++;
	}
	free(array);
	return (1);
}
