#include "sort.h"

/**
 * swap - Swaps the value pointed by two integer pointers
 *
 * @a: Pointer to the integer to swap
 * @b: Pointer to the integer to swap
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
 * partition - Partitions an array based on a pivot value
 *
 * @arr: Integer array to partition
 * @low: Lower bound of the array to partition
 * @high: Upper bound of the array to partition
 * @size: Size of the array
 *
 * Return: Nothing
 */
int partition(int *arr, int low, int high, unsigned int size)
{
	int j, i, pivot;

	pivot = arr[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (i != j)
	{
		swap(&arr[i], &arr[high]);
		print_array(arr, size);
	}
	return (i);
}

/**
 * quick_sort_recursion - Implementation of the quick sort algorithm
 *
 * @array: Integer array to sort
 * @low: Lower bound of the array to sort
 * @high: Upper bound of the array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort_recursion(int *array, int low, int high, unsigned int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quick_sort_recursion(array, low, pi - 1, size);
		quick_sort_recursion(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - A wrapper for the quick_sort_recursion function
 *
 * @array: Integer array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, unsigned int size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
