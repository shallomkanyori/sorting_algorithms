#include "sort.h"

void quicksort_hoare(int *array, size_t size, ssize_t start, ssize_t end);
ssize_t partition_hoare(int *array, size_t size, ssize_t start, ssize_t end);
void swap(int *array, ssize_t a, ssize_t b);

/**
 * quick_sort_hoare - quick sorts an integer array using Hoare partition
 * @array: the array
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, size, 0, size - 1);
}

/**
 * quicksort_hoare - recursively Hoare quick sorts an integer array
 * @array: the array
 * @size: the size of the array
 * @start: the start index of the partition
 * @end: the last index of the partition
 */
void quicksort_hoare(int *array, size_t size, ssize_t start, ssize_t end)
{
	ssize_t p_ind;

	if (start < end)
	{
		p_ind = partition_hoare(array, size, start, end);

		quicksort_hoare(array, size, start, p_ind);
		quicksort_hoare(array, size, p_ind + 1, end);
	}
}

/**
 * partition_hoare - hoare partitions an integer array for quicksort
 * @array: the array
 * @size: the size of the array
 * @start: the start index of the previous partition
 * @end: the end index of the previous partition
 *
 * Return: the dividing index for the partitions
 */
ssize_t partition_hoare(int *array, size_t size, ssize_t start, ssize_t end)
{
	int pivot = array[end];
	ssize_t i = start - 1;
	ssize_t j = end + 1;

	while (1)
	{
		do i++;
		while (array[i] < pivot);

		do j--;
		while (array[j] > pivot);

		if (i >= j)
		{
			j = j == end ? j - 1 : j;
			return (j);
		}

		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * swap - swaps two elements in an integer array
 * @array: the array
 * @a: the index of the first element
 * @b: the index of the second element
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}
