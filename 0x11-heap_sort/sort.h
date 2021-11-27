#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct MaxHeap - struct array
 * @size: array size
 * @array: array data
 *
 * Description: structure MaxHeap
 * for Heap sort algorhimt
 */

struct MaxHeap
{
	int size;
	int *array;
};

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
struct MaxHeap *createAndBuildHeap(int *array, int size);
void maxHeapify(struct MaxHeap *, int idx, size_t size_t);
void swap(int *a, int *b);

#endif /*_HEAP_SORT_H_ */
