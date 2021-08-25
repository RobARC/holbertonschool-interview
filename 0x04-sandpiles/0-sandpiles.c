  #include "sandpiles.h"

/**
 *print_grid - Print 3x3 grids
 *@grid: Left 3x3 grid
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - sum grid1 + grid2
 * @grid1: Left 3x3 grid
 * @grid2: right 3x3 grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	print_grid(grid1);

	while (stable(grid1) != 0)
	{
		tupple(grid1, grid2);
	}
}

/**
 * tupple - transform the matrix in stable matrix
 * @grid1: Left 3x3 grid
 * @grid2: right 3x3 grid
 *
 */

void tupple(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, num = 0, size = 3;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			num = grid1[i][j];
			if (num < 4)
			{
			grid2[i][j] = grid1[i][j];
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			num = grid1[i][j];
			if (num >= 4)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if (j < 2)
					grid1[i][j + 1]++;
				if (i < 2)
					grid1[i + 1][j]++;
				if (j > 0)
					grid1[i][j - 1]++;
				if (i > 0)
					grid1[i - 1][j]++;
			}
		}
	}
	if (stable(grid1) == 1)
	{
		printf("=\n");
		print_grid(grid1);
	}
}

/**
 * stable - Checks if the 3x3 grid is stable
 * @grid: 3x3 int grid.
 * Return: 0 if stable(all numbers less than 3)
 *         1 if not.
 */

int stable(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}
