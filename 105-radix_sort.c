#include "sort.h"

void counting_sort_digit(int *array, size_t size, int exp);

/**
 * radix_sort - radix sorts an array of integers
 * @array: the array
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int exp, max;
	size_t i;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		max = array[i] > max ? array[i] : max;

	exp = 1;
	while ((max / exp) >= 1)
	{
		counting_sort_digit(array, size, exp);
		exp *= 10;
		print_array(array, size);
	}
}

/**
 * counting_sort_digit - counting sorts an integer array based on a certain
 * digit
 * @array: the array
 * @size: the size of the array
 * @exp: the position of the digit to sort by as a power of 10
 */
void counting_sort_digit(int *array, size_t size, int exp)
{
	int *array_cpy;
	int count[10] = {0};
	size_t i;
	int ind;

	array_cpy = malloc(sizeof(int) * size);
	if (!array_cpy)
		return;

	for (i = 0; i < size; i++)
	{
		ind = array[i] / exp;
		count[ind % 10]++;

		array_cpy[i] = array[i];
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (size - 1); i > 0; i--)
	{
		ind = array_cpy[i] / exp;
		array[--count[ind % 10]] = array_cpy[i];
	}

	ind = array_cpy[0] / exp;
	array[--count[ind % 10]] = array_cpy[0];

	free(array_cpy);
}
