#ifndef _HEAP_SORT_H_
#define _HEEP_SORT_H_

#include <stdio.h>
#include <stdlib.h>

/** Struct for elements of the current heap */

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