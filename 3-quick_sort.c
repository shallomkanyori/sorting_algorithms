#include "sort.h"

void quicksort_rec(int *array, size_t size, size_t start, size_t end);
size_t partition(int *array, size_t size, size_t start, size_t end);

/**
 * quick_sort - quick sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	quicksort_rec(array, size, 0, size - 1);
}

/**
 * quicksort_rec - recursively quick sorts an array of integers
 * @array: the array
 * @size: the size of the array
 * @start: the firt ind of the partition
 * @end: the last ind of the partition
 */
void quicksort_rec(int *array, size_t size,  size_t start, size_t end)
{
	size_t p_ind;

	if (start >= end)
		return;

	p_ind = partition(array, size, start, end);

	if (p_ind > 0)
		quicksort_rec(array, size, start, p_ind - 1);

	quicksort_rec(array, size, p_ind + 1, end);
}

/**
 * partition - Lomuto partitions an array for quick sort
 * @array: the array
 * @size: the size of the array
 * @start: the first in of the previous partition
 * @end: the last ind of the previous partition
 *
 * Return: the index of the pivot
 */
size_t partition(int *array, size_t size, size_t start, size_t end)
{
	int pivot = array[end];
	int p_ind = (int)start - 1;
	size_t i;
	int tmp;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			p_ind++;
			tmp = array[p_ind];
			array[p_ind] = array[i];
			array[i] = tmp;

			if ((size_t)p_ind != i)
				print_array(array, size);
		}
	}

	p_ind++;
	tmp = array[p_ind];
	array[p_ind] = array[end];
	array[end] = tmp;

	if ((size_t)p_ind != end)
		print_array(array, size);

	return ((size_t)p_ind);
}
