#include "sort.h"

/**
 * swap - swaps the value of two integer pointers
 *
 * @a: Integer pointer argument to swap with b
 * @b: Integer pointer argument to swap with a
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers using the Selection Sort method
 *
 * @array: Integer array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, unsigned int size)
{
	unsigned int i, j;

	if (array == (void *) 0)
		return;
	for (i = 0; i < size; i++)
	{
		unsigned int min_index;

		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
