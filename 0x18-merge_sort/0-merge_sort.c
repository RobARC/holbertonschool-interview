#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * merger - merges subarrays
 *
 * @array: array
 * @my_array: subarray
 * @left: left index
 * @med: middle index
 * @right: right index
 */
void merger(int *array, int *my_array, int left, int med, int right)
{
	int i, j, k;

	printf("Mergin...\n");
	printf("[left]: ");
	print_array(array + left, med - left);
	printf("[right]: ");
	print_array(array + med, right - med);

	for (i = left, j = med, k = 0; i < med && j < right; k++)
	{
		if (array[i] < array[j])
			my_array[k] = array[i++];
		else
			my_array[k] = array[j++];
	}
	while (i < med)
	{
		my_array[k++] = array[i++];
	}
	while (j < right)
	{
		my_array[k++] = array[j++];
	}
	for (i = left, k = 0; i < right; i++)
		array[i] = my_array[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * split_sort - splits array
 *
 * @array: array
 * @my_array: subarray
 * @left: left index
 * @right: right index
 */
void split_sort(int *array, int *my_array, int left, int right)
{
	int med;

	if (right - left > 1)
	{
		med = left + (right - left) / 2;
		split_sort(array, my_array, left, med);
		split_sort(array, my_array, med, right);
		merger(array, my_array, left, med, right);
	}
}

/**
 * merge_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void merge_sort(int *array, size_t size)
{
	int *my_array;

	if (size <= 1)
	{
		printf("Array is ordered");
		return;
	}
	else
	{
		my_array = malloc(sizeof(int) * size);
		split_sort(array, my_array, 0, size);
		free(my_array);
	}
}
