#include "sort.h"

void top_down_split_merge(int *a, ssize_t mid, ssize_t end, int *b);
void top_down_merge(int *b, ssize_t start, ssize_t mid, ssize_t end, int *a);

/**
 * merge_sort - merge sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *b;
	size_t i;

	if (!array || size < 2)
		return;

	b = malloc(sizeof(int) * size);
	if (!b)
		return;

	for (i = 0; i < size; i++)
		b[i] = array[i];

	top_down_split_merge(array, 0, size, b);

	free(b);
}

/**
 * top_down_split_merge - top down merge sorts an integer array
 * @b: the array to sort
 * @start: the start index of the sorting range, inclusive
 * @end: the end index of the sorting range, exclusive
 * @a: a working array to store the sort result
 */
void top_down_split_merge(int *b, ssize_t start, ssize_t end, int *a)
{
	ssize_t mid;

	if ((end - start) <= 1)
		return;

	mid = (end + start) / 2;

	top_down_split_merge(a, start, mid, b);
	top_down_split_merge(a, mid, end, b);

	top_down_merge(b, start, mid, end, a);
}

/**
 * top_down_merge - merges a to b from start to end -1
 * @b: the array to merge to
 * @start: the index to start merging from, inclusive
 * @mid: the middle index (a[start,mid) and a[mid, end) are sorted)
 * @end: the index to finish merging at, exclusive
 * @a: the array to merge from
 */
void top_down_merge(int *b, ssize_t start, ssize_t mid, ssize_t end, int *a)
{
	ssize_t i = start, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(&a[start], mid - start);
	printf("[right]: ");
	print_array(&a[mid], end - mid);

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || a[i] <= a[j]))
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array(&b[start], end - start);
}
