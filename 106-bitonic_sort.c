#include "sort.h"

void bitonic_sort_rec(int *array, size_t size, size_t start, size_t n,
		int dir);
void bitonic_merge(int *array, size_t size, size_t start, size_t n, int dir);
void comp_swap(int *array, size_t a, size_t b, int dir);

/**
 * bitonic_sort - bitonic sorts an integer array
 * @array: the array
 * @size: the size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_rec(array, size, 0, size, 1);
}

/**
 * bitonic_sort_rec - recursively bitonic sorts an integer array
 * @array: the array
 * @size: the size of the array
 * @start: the index to start sorting, inclusive
 * @n: the number of elements to sort
 * @dir: the direction to sort in, 1 for ascending, 0 for descending
 */
void bitonic_sort_rec(int *array, size_t size,  size_t start, size_t n,
		int dir)
{
	size_t k;

	if (n > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", n, size,  dir ? "UP" : "DOWN");
		print_array(&array[start], n);

		k = n / 2;

		bitonic_sort_rec(array, size, start, k, 1);
		bitonic_sort_rec(array, size, start + k, k, 0);

		bitonic_merge(array, size, start, n, dir);

		printf("Result [%lu/%lu] (%s):\n", n, size, dir ? "UP" : "DOWN");
		print_array(&array[start], n);
	}
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence in a given direction
 * @array: the array
 * @size: the size of the array
 * @start: the index to start sorting, inclusive
 * @n: the number of elements to sort
 * @dir: the direction to sort in, 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t n, int dir)
{
	size_t k, i;

	if (n > 1)
	{
		k = n / 2;
		for (i = start; i < start + k; i++)
			comp_swap(array, i, i + k, dir);

		bitonic_merge(array, size, start, k, dir);
		bitonic_merge(array, size, start + k, k, dir);
	}
}

/**
 * comp_swap - swaps two elements of an integer array after comparing
 * @array: the array
 * @a: the index of the first element
 * @b: the index of the second element
 * @dir: the direction of comparison, 1 if ascending, 0 if descending
 */
void comp_swap(int *array, size_t a, size_t b, int dir)
{
	int tmp;

	if ((array[a] > array[b] && dir == 1) ||
		(array[a] < array[b] && dir == 0))
	{
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
	}
}
