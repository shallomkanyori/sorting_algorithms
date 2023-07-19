#include "sort.h"

/**
 * bubble_sort - bubble sorts an array of integers in ascending order
 * @array: the array
 * @size: the size of the array
 *
 * Returns: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped = 1;
	int tmp;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				swapped = 1;
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
