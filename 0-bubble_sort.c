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
 * bubble_sort - Sorts an array using the Bubble Sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, unsigned int size)
{
	unsigned int i;
	unsigned short swapped;

	swapped = 0;
	for (i = 0; i < size; i++)
	{
		unsigned int j;

		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped++;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			return;
	}
}
