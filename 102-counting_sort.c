#include "sort.h"

/**
 * counting_sort - counting sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k = 0, j;
	int *count, *array_cpy;

	if (!array || size < 2)
		return;

	array_cpy = malloc(sizeof(int) * size);
	if (!array_cpy)
		return;

	for (i = 0; i < size; i++)
	{
		k = array[i] > k ? array[i] : k;
		array_cpy[i] = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (!count)
	{
		free(array_cpy);
		return;
	}

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j <= k; j++)
		count[j] += count[j - 1];

	print_array(count, k + 1);

	for (i = (size - 1); i > 0; i--)
		array[--count[array_cpy[i]]] = array_cpy[i];

	array[--count[array_cpy[0]]] = array_cpy[0];

	free(count);
	free(array_cpy);
}
