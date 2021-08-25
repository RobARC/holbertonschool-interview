  #include "sandpiles.h"

  /**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
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

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  int i, j, grid3[3][3];
  
  printf("=\n");
  
    for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
      {
        grid3[i][j] = grid1[i][j] + grid2[i][j];
      }
    }
    print_grid(grid3);
    
    while (stable(grid3) != 0)
    {
      printf("=\n");
      tupple(grid3, grid2);
      
    }
}

void tupple(int sandpiles[3][3], int grid2[3][3])
{
  int i, j, size = 3;
    
  for (i = 0; i < size; i++)
  {
        for (j = 0; j < size; j++)
        {
          int num = sandpiles[i][j];
          if (num < 4)
            {
                grid2[i][j] = sandpiles[i][j];
            }
        }
  }
  for (i = 0; i < size; i++)
  {
        for (j = 0; j < size; j++)
        {
          int num = sandpiles[i][j];
          if (num >= 4)
            {
                sandpiles[i][j] = sandpiles[i][j] -4;
                if (j < 2)
                    sandpiles[i][j + 1]++;
                if (i < 2)
                  sandpiles[i + 1][j]++;
                if (j > 0)
                  sandpiles[i][j - 1]++;
                if (i > 0)
                  sandpiles[i - 1][j]++;
             
            }
        }
  }
  
  print_grid(sandpiles);
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
				return(1);
	return(0);
}