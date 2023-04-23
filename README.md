Project Name: Sorting algorithms & Big O
Language: C
Constituents: Algorithm, Data Structure

General:
- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm

Data Stuctures and Functions
For this project I was given the following print_array, and print_list functions:

	#include <stdlib.h>
	#include <stdio.h>
	/**
	 * print_array - Prints an array of integers
	 *
	 * @array: The array to be printed
	 * @size: Number of elements in @array
	 */
	void print_array(const int *array, size_t size)
	{
	    size_t i;

	    i = 0;
	    while (array && i < size)
	    {	
	        if (i > 0)
        	    printf(", ");
	        printf("%d", array[i]);
	        ++i;
	    }
	    printf("\n");
	}

	#include <stdio.h>
	#include "sort.h"
	/**
	 * print_list - Prints a list of integers
	 *
	 * @list: The list to be printed
	 */
	void print_list(const listint_t *list)
	{
	    int i;

	    i = 0;
	    while (list)
	    {
	        if (i > 0)
        	    printf(", ");
	        printf("%d", list->n);
	        ++i;
	        list = list->next;
	    }
	    printf("\n");
	}

Data Structure to use for doubly linked list:

	/**
	 * struct listint_s - Doubly linked list node
	 *
	 * @n: Integer stored in the node
	 * @prev: Pointer to the previous element of the list
	 * @next: Pointer to the next element of the list
	 */
	typedef struct listint_s
	{
	    const int n;
	    struct listint_s *prev;
	    struct listint_s *next;
	} listint_t;

We are tasked with implementing different types of sorting algorithms as well as stating the big O notation for the time complexity of the algorithm used.
Some of the algorithms included:
- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort

	The source files contained in this repo contains implmentation for a type of sorting algorithm.
The other(s) contains a dictation of the big O notations of the time complexity if the algorithm, with 1 notation per line as follows:
- In the best case
- In the average case
- In the worst case
