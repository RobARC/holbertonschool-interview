#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_sort(int *array, int *my_array, int left, int right);
void merger(int *array, int *my_array, int left, int mid, int right);

#endif
