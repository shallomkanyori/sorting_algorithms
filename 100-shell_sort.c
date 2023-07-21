#include "sort.h"

/**
 * shell_sort - shell sorts an array of integers using the Knuth sequence
 * @array: the array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int tmp;

	if (!array || size < 2)
		return;

	while (gap <= (size / 3))
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
