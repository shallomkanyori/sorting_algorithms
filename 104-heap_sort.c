#include "sort.h"

void heapify(int *array, ssize_t size);
void sift_down(int *array, ssize_t size, ssize_t start, ssize_t end);
void swap(int *array, ssize_t a, ssize_t b);

/**
 * heap_sort - heap sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	end = size - 1;
	while (end > 0)
	{
		swap(array, end, 0);
		print_array(array, size);
		end--;
		sift_down(array, size,  0, end);
	}
}

/**
 * heapify - builds a max heap in an array of integers
 * @array: the array
 * @size: the size of the array
 */
void heapify(int *array, ssize_t size)
{
	ssize_t last = size - 1;
	ssize_t start = (last - 1) / 2; /* start at the last parent node's index */

	while (start >= 0)
	{
		sift_down(array, size, start, size - 1);
		start--;
	}
}

/**
 * sift_down - repair the heap rooted at start
 * @array: the array
 * @size: the size of the array
 * @start: the index of the root
 * @end: the index of the last node in the heap
 */
void sift_down(int *array, ssize_t size, ssize_t start, ssize_t end)
{
	ssize_t root = start;
	ssize_t child, swap_ind;

	while ((2 * root + 1) <= end)
	{
		child = 2 * root + 1;
		swap_ind = root;

		/* check the left child */
		if (array[swap_ind] < array[child])
			swap_ind = child;

		/* check the right child */
		if ((child + 1) <= end && array[swap_ind] < array[child + 1])
			swap_ind = child + 1;

		if (swap_ind == root)
		{
			/* the root holds the largest element */
			return;
		}
		else
		{
			swap(array, root, swap_ind);
			print_array(array, size);
			root = swap_ind;
		}
	}
}

/**
 * swap - swaps two elements in an integer array
 * @array: the array
 * @a: the index of first element
 * @b: the index of the second element
 */
void swap(int *array, ssize_t a, ssize_t b)
{
	int tmp = array[a];

	array[a] = array[b];
	array[b] = tmp;
}
