/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roherrer <roherrer@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:59:35 by roherrer          #+#    #+#             */
/*   Updated: 2024/06/02 17:59:39 by roherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	create_grid(int **grid);
void	print_grid(int **grid);
void	print_error(void);
int		input_clues(char *argv, int *clues);
int		check_box(int **grid, int *clues);
int		num_valid(int **grid, int row, int col, int num);

int	solve(int **grid, int *clues, int pos)
{
	int	row;
	int	col;
	int	num;

	row = pos / 4;
	col = pos % 4;
	num = 1;
	if (pos == 16)
		return (check_box(grid, clues));
	if (grid[row][col] != 0)
		return (solve(grid, clues, pos + 1));
	while (num <= 4)
	{
		if (num_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	**grid;

	grid = (int **) malloc(4 * 4);
	create_grid(grid);
	clues = (int *) malloc(16 * 4);
	if (argc != 2)
		print_error();
	if (!input_clues(argv[1], clues))
	{
		print_error();
		free(clues);
	}
	else if (solve(grid, clues, 0))
		print_grid(grid);
	else
		print_error();
	free(grid);
	free(clues);
	return (0);
}
