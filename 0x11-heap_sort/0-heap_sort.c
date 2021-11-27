#include "sort.h"

/**
 * heap_sort - function to sort heap
 * 
 * @array pointer variable to the array
 * @size  variable size
 */

//funtion to swap integers
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(struct MaxHeap *maxHeap, int idx, size_t size)
{

    int largest = idx;          //Initialize largest as root
    int left = (idx << 1) + 1;  // left = 2 * idx +1
    int right = (idx + 1) << 1; // right = 2 * idx +2

    // See if left child of root exists and is greater than
    // root
    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;

    // See if right child of root exists and is greater than
    // the largest so far
    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    if (largest != idx)
    {
        swap(&maxHeap->array[largest], &maxHeap->array[idx]);
        print_array(maxHeap->array, size);
        maxHeapify(maxHeap, largest, size);
    }
}

struct MaxHeap *createAndBuildHeap(int *array, int size)
{
    int i;
    struct MaxHeap *maxHeap = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   //Initialize size of heap;
    maxHeap->array = array; //Assing address of first element of the array

    for (i = (size - 2) / 2; i >= 0; --i)
    {
        maxHeapify(maxHeap, i, size);
    }
    return maxHeap;
}

void heap_sort(int *array, size_t size)
{
    //Buils a heap from input data.

    struct MaxHeap *maxHeap = createAndBuildHeap(array, size);

    //Repeat following steps while heap size is greater than 1
    while (maxHeap->size > 1)
    {
        // The largest item in Heap is stored at the root. Replace
        // it with the last item of the heap followed by reducing the
        // size of heap by 1.

        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        print_array(array, size);
        --maxHeap->size; //Reduce heap size

        maxHeapify(maxHeap, 0, size);
    }
}