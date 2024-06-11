/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarrio <rbarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:14:09 by rbarrio           #+#    #+#             */
/*   Updated: 2024/06/11 20:13:23 by rbarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	printError(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
	{
		len++;
	}
	write(1, msg, len);
}

int open_file(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
    if (*fd == -1)
    {
        printError("File error\n");
        return (0);
    }
	return (1);
}

int count_lines(char *filename, int *num_lines)
{
    int bytes;
	char buffer[4096];
	int i;
	int fd;
	
	if (open_file(filename, &fd) == 0)
		return (0);
    *num_lines = 1;
    while ((bytes = read(fd, buffer, 4096)) > 0)
	{
		i = 0;
        while (i < bytes)
		{
            if (buffer[i] == '\n' && i != 0)
                *num_lines += 1;
			i++;
        }
    }
    if (bytes == -1)
	{
        printError("File Error\n");;
        return (0);
    }
	close(fd);
	return (1);
}

int create_array(char **str, int len)
{
	*str = malloc(len + 1);
	if (*str == NULL)
	{
		//free(str);
		return (0);
	}
	return (1);
}

int len_lines(char **matrix, char *filename, int num_lines)
{
    int bytes;
	char buffer[4096];
	int i;
	int fd;
	int j;
	int len;
	int k;
	
	i = 0;
	j = 0;
	if (open_file(filename, &fd) == 0)
		return (0);
    while ((bytes = read(fd, buffer, 4096)) > 0)
    {
        i = 0;
        while (j < num_lines && i < bytes)
        {
            len = 0;
            while (i < bytes && buffer[i] != '\n' && buffer[i] != '\0')
            {
                len++;
                i++;
            }
            if (create_array(&matrix[j], len) == 0)
            {
                close(fd);
                return 0;
            }
            k = 0;
            while (k < len)
            {
                matrix[j][k] = buffer[i - len + k];
                k++;
            }
            matrix[j][len] = '\0';
            j++;
            if (i < bytes && (buffer[i] == '\n' || buffer[i] == '\0'))
                i++;
        }
    }
    if (bytes == -1)
	{
        printError("File Error\n");
        return (0);
    }
	close(fd);
	return(1);
}

char **create_matrix(char *filename, int *num_lines)
{
    char **matrix;
	
	if (count_lines(filename, num_lines) == 0)
		return (0);
	matrix = malloc(sizeof(char *) * (*num_lines));
	if (matrix == NULL)
	{
		printError("Matrix Error\n");;
        return (NULL);	
	}
	if (len_lines (matrix, filename, *num_lines) == 0)
	{
		printError("Matrix Error\n");;
        return (NULL);
	}
	return(matrix);
}

void print_matrix(char **matrix, int num_lines)
{
    int i;

    i = 0;
    while (i < num_lines)
    {
        printf("%s\n", matrix[i]);
		//free(matrix[i]);
        i++;
    }
}

int column_empty(char **matrix, char empty, int *coor, int size)
{
	int row;

	row = coor[0];
	while (size >= 0)
	{
		if (matrix[row][coor[1]] != empty)
		{
			printf("row: %c\n", matrix[row][coor[1]]);
			return (0);
		}
		row--;
		size--;
	}
	return (1);
}

int row_empty(char **matrix, char empty, int *coor, int size)
{
	int col;

	col = coor[1];
	while (size >= 0)
	{
		if (matrix[coor[0]][col] != empty)
		{
			printf("col: %c\n", matrix[coor[0]][col]);
			return (0);
		}
		col--;
		size--;
	}
	return (1);
}

int aux(char **matrix, char empty, int *coor, int *lens)
{
	int size;
	int pos[2];

	size = 0;
	pos[0] = coor[0];
	pos[1] = coor[1];
	printf("num_lines: %d\n", lens[0]);
	while (pos[0] < lens[0] && pos[1] < lens[1])
	{
		printf("row: %d, col: %d\n", pos[0], pos[1]);
		if(column_empty(matrix, empty, pos, size) == 0 || row_empty(matrix, empty, pos, size) == 0)
			return(size);
		size++;		
		pos[0]++;
		pos[1]++;
	}
	return (size);
}

void result_to_matrix(char **matrix, char full, int *result)
{
	int size;
	int size2;
	int i;
	int j;

	i = result[0];
	size = result[2];
	while (size > 0)
	{
		j = result[1];
		size2 = result[2];
		while (size2 > 0)
		{
			matrix[i][j] = full;
			j++;
			size2--;
		}
		size--;
		i++;	
	}
}

void result(char **matrix, char empty, char full, int *lens)
{
	int coor[2];
	int result[3];
	int size;

	coor[0] = 0;
	result[2] = 0;
	while (coor[0] < lens[0] && result[2] < lens[0])
	{
		coor[1] = 0;
		while(coor[1] < lens[1] && result[2] < lens[0])
		{
			if (matrix[coor[0]][coor[1]] == empty)
			{
				size = aux(matrix, empty, coor, lens);
				if (size > result[2])
				{
					result[0] = coor[0];
					result[1] = coor[1];
					result[2] = size;
					printf("size: %d\n", size);
				}
			}
			coor[1] += 1;
		}
		coor[0] += size + 1;
	}
	result_to_matrix(matrix, full, result);
}

void solve(char **matrix, int *lens)
{
	char empty;
	char obs;
	char full;

	empty = matrix[0][1];
	obs = matrix[0][2];
	full = matrix[0][3];
	matrix = &matrix[1];
	lens[0] -= 1;
	print_matrix(matrix, lens[0]);
	result(matrix, empty, full, lens);
	print_matrix(matrix, lens[0]);
}


int	size_lines(char *matrix)
{
	int len;

	len = 0;
	while(matrix[len])
	{
		len++;
	}
	return (len);
}

int	chek_len_lines(char **matrix, int num_lines)
{
	int len;
	int i;

	i = 1;
	printf("HERE");
	len = size_lines(matrix[i]);
	printf("HERE1");
	i++;
	while (size_lines(matrix[i]) == len && i < num_lines)
	{
		i++;
	}
	printf("HERE2");
	if(num_lines == i)
		return (len);
	return (0);
}

int	chek_chars_in_map(char **matrix, int *lens)
{
	int i;
	int j;
	
	i = 1;
	printf("HERE\n");
	while (i < lens[0])
	{
		j = 0;
		printf("HERE1\n");
		while (j < lens[1])
		{
			printf("HERE2: %c\n", matrix[0][1]);
			if (matrix[i][j] != matrix[0][1])
			{
				printf("HERE3: %c\n", matrix[0][2]);
				if (matrix[i][j] != matrix[0][2])
				{
					printf("HERE4: %c\n", matrix[0][3]);
					if (matrix[i][j] != matrix[0][3])
						printf("HERE5: %c\n", matrix[i][j]);
						return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	chek_chars(char **matrix, int *lens)
{
	int i; 

	i = 1;
	if (size_lines(matrix[0]) != 4)
		return (0);
	if (!(matrix[0][0] > '0' && matrix[0][0] <= '9'))
		return (0);
	while(i < 4)
	{
		if(!(matrix[0][i] >= ' ' && matrix[0][i] <= '~'))
			return(0);
		i++;
	}
	if (matrix[0][1] == matrix[0][2] || matrix[0][1] == matrix[0][3])
		return (0);
	if (matrix[0][2] == matrix[0][3])
		return (0);
	if (chek_chars_in_map(matrix, lens) == 0)
		return (0);
	return (1);
}


int	check_map(char **matrix, int *lens)
{
	printf("HERE");
	lens[1] = chek_len_lines(matrix, lens[0]);
	if (lens[1] == 0)
		return (0);
	if (chek_chars(matrix, lens) == 0)
		return (0);
	
	return (1);
}


int main (int argc, char *argv[])
{
    char **matrix;
    int lens[2];
	int i;

    if (argc > 1)
    {
		i = 1;
		while (i < argc)
		{
			lens[0] = 0;
			lens[1] = 0;
			matrix = create_matrix(argv[i], &lens[0]);
			if (check_map(matrix, lens) == 0)
			{
				printError("map error");
				return (1);
			}
			else
			{
				solve(matrix, lens);
				i++;
			}

			if(argc > 2)
				write(1, "\n", 1);
		}
    }
    return (0);
}