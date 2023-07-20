#include "sort.h"

/**
 * selection_sort - selection sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_ind;
	int tmp;

	for (i = 0; i < size; i++)
	{
		min_ind = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min_ind])
				min_ind = j;
		}

		tmp = array[i];
		array[i] = array[min_ind];
		array[min_ind] = tmp;
		print_array(array, size);
	}
}
