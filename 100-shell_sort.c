#include "sort.h"
#include <stdbool.h>

/**
 * swap - Swaps two integer values
 *
 * @a: Pointer to first integer to swap
 * @b: Pointer to second integer to swap
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
 * knuth_gap - Used to get the knuth term of the ith sequence
 *
 * @i: Knuth term to retrieve
 *
 * Return: ith Knuth term
 */
int knuth_gap(int i)
{
	return (i * 3 + 1);
}

/**
 * largest_knuth_gap - computes and returns the largest knuth term <= n
 *
 * @n: Upper bound for the knuth term to retrieve
 *
 * Return: Knuth term
 */
int largest_knuth_gap(int n)
{
	int prev_gap, gap;

	prev_gap = 0;
	gap = knuth_gap(prev_gap);
	while (gap < n)
	{
		prev_gap = gap;
		gap = knuth_gap(gap);
	}
	return (prev_gap);
}

/**
 * shell_sort - Sorts array using the shell sort method
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, unsigned int size)
{
	unsigned int index;
	int gap;

	if (array == (void *) 0 || size <= 1)
		return;
	gap = largest_knuth_gap(size);
	while (gap > 0)
	{
		int i;

		for (index = gap, i = index - gap; index < size;
				index++, i = index - gap)
		{
			if (array[i] > array[index])
			{
				int idx;
				bool swapped;

				swap(&array[index], &array[i]);
				idx = i;
				swapped = true;
				while (idx - gap >= 0 && swapped)
				{
					swapped = false;
					if (array[idx] < array[idx - gap])
					{
						swap(&array[idx], &array[
								idx - gap]);
						idx -= gap;
						swapped = true;
					}
				}
			}
		}
		gap = largest_knuth_gap(gap);
		print_array(array, size);
	}
}
