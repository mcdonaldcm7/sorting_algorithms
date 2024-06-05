#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges the left_array and right_array in a sorted manner
 *
 * @array: array containing elements
 * @low: rightmost index of the subarray
 * @mid: middle index of the subarray
 * @high: leftmost index of the subarray
 */
void merge(int *array, unsigned int low, unsigned int mid, unsigned int high)
{
	int left_length, right_length, *merged_array, l, h, i;

	left_length = mid - low + 1;
	right_length = high - mid;
	merged_array = (int *) malloc((left_length + right_length) * sizeof(int));

	for (i = 0; i < (left_length + right_length); i++)
		merged_array[i] = array[low + i];

	for (l = 0, h = left_length, i = low; i <= high; i++)
	{
		if (h > (right_length + left_length - 1) || merged_array[l] <=
				merged_array[h])
			array[i] = merged_array[l++];
		else
			array[i] = merged_array[h++];
	}

	printf("Merging...\n[left]: ");

	for (i = 0; i < (left_length + right_length); i++)
	{
		if (i > 0 && i != left_length)
			printf(", ");
		if (i == left_length)
			printf("\n[right]: ");
		printf("%d", merged_array[i]);
	}

	printf("\nDone: ");
	for (i = low; i <= high; i++)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
	free(merged_array);
}

/**
 * merge_sort_array - Sorts an array using the merge sort algorithm
 *
 * @array: Array to sort
 * @low: starting index of the subarray
 * @high: end index of the subarray
 */
void merge_sort_array(int *array, unsigned int low, unsigned int high)
{
	unsigned int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		merge_sort_array(array, low, mid);
		merge_sort_array(array, mid + 1, high);
		merge(array, low, mid, high);
	}

}

/**
 * merge_sort - Wrapper for the merge_sort_work_array function
 *
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, unsigned int size)
{
	if (array == (void *) 0 || size <= 1)
		return;
	merge_sort_array(array, 0, size - 1);
}
