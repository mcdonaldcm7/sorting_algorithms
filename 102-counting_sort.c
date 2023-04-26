#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array using the counting sort algortihm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, unsigned int size)
{
	unsigned int i, count_size;
	int max, count_i, output_idx;
	int *count, *output;

	if (array == (void *) 0 || size == 0 || size == 1)
		return;
	max = array[0];
	for (i = 1; i < size; i++)
		max = array[i] > max ? array[i] : max;
	count_size = max + 1;
	count = malloc(sizeof(*count) * count_size);
	output = malloc(sizeof(*output) * size);
	if (count == (void *) 0 || output == (void *) 0)
		return;
	for (i = 0; i < count_size; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	output_idx = size - 1;
	for (count_i = count_size - 1; count_i >= 0; count_i--)
	{
		int freq, j;

		if (count[count_i] > 0)
		{
			freq = count[count_i];
			for (j = output_idx; j > (output_idx - freq); j--)
				output[j] = count_i;
			output_idx = j;
		}
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	for (i = 1; i < count_size; i++)
		count[i] += count[i - 1];
	print_array(count, count_size);
	free(count);
	free(output);
}
