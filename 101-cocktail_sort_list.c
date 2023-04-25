#include "sort.h"
#include <stdbool.h>

/**
 * swap_node - Swaps two nodes of a doubly linked list
 *
 * @a: Node to swap (Should precede b)
 * @b: Node to swap
 *
 * Return: Nothing
 */
void swap_node(listint_t *a, listint_t *b)
{
	a->next = b->next;
	b->prev = a->prev;
	if (a->prev != (void *) 0)
		a->prev->next = b;
	a->prev = b;
	if (b->next != (void *) 0)
		b->next->prev = a;
	b->next = a;
}

/**
 * cocktail_sort_iteration_backward - Backward iteration for the cocktail sort
 * function
 *
 * @fr_node: Pointer to the address of the lower bound node
 * @la_node: Pointer to the address of the upper bound node
 * @iter: Pointer to the address of the node used for iteration
 * @list: Pointer to the head of the doubly linked list if integers
 *
 * Return: true if there was a swap while traversing the list, Otherwise false
 */
bool cocktail_sort_iteration_backward(listint_t **fr_node, listint_t **la_node,
		listint_t **iter, listint_t **list)
{
	bool brk, iter_swap, swapped;

	swapped = false;
	while (*iter != *fr_node)
	{
		iter_swap = brk = false;
		if ((*iter)->n < (*iter)->prev->n)
		{
			if ((*iter)->prev == *fr_node)
				brk = true;
			if (*iter == *la_node)
				*la_node = (*iter)->prev;
			swap_node((*iter)->prev, *iter);
			if ((*iter)->prev == (void *) 0)
				*list = *iter;
			print_list(*list);
			iter_swap = swapped = true;
		}
		if (!iter_swap)
			*iter = (*iter)->prev;
		if (brk)
			break;
	}
	return (swapped);
}

/**
 * cocktail_sort_iteration_forward - Forward iteration for the cocktail sort
 * function
 *
 * @fr_node: Pointer to the address of the lower bound node
 * @la_node: Pointer to the address of the upper bound node
 * @iter: Pointer to the address of the node used for iteration
 * @list: Pointer to the head of the doubly linked list if integers
 *
 * Return: true if there was a swap while traversing the list, Otherwise false
 */

bool cocktail_sort_iteration_forward(listint_t **fr_node, listint_t **la_node,
		listint_t **iter, listint_t **list)
{
	bool brk, iter_swap, swapped;

	swapped = false;
	while ((*iter)->next != *la_node)
	{
		brk = iter_swap = false;
		if ((*iter)->n > (*iter)->next->n)
		{
			if ((*iter)->next == *la_node)
				brk = true;
			if (*iter == *fr_node)
				*fr_node = (*iter)->next;
			swap_node(*iter, (*iter)->next);
			if ((*iter)->prev->prev == (void *) 0)
				*list = (*iter)->prev;
			print_list(*list);
			iter_swap = swapped = true;
		}
		if (!iter_swap)
			*iter = (*iter)->next;
		if (brk)
			break;
	}
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts an array using the coktail sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list of integers to sort
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *fr_node, *la_node, *iter;
	bool swapped;

	if (list == (void *) 0 || *list == (void *) 0)
		return;
	fr_node = *list;
	la_node = (void *) 0;
	swapped = true;
	while (swapped)
	{
		iter = fr_node;
		swapped = cocktail_sort_iteration_forward(&fr_node,
				&la_node, &iter, list);
		if (!swapped)
			break;
		la_node = iter;
		swapped = cocktail_sort_iteration_backward(&fr_node,
				&la_node, &iter, list);
		fr_node = iter->next;
	}
}

