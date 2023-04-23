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
 * insertion_sort_list - Sorts a doubly linked list using insertion sort method
 *
 * @list: Pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_iter, *rev_iter;
	bool swapped;
	curr_iter = *list;
	while (curr_iter != (void *) 0 && curr_iter->next != (void *) 0)
	{
		if (curr_iter->n > curr_iter->next->n)
		{
			rev_iter = curr_iter->next;
			swap_node(curr_iter, rev_iter);
			swapped = true;
			print_list(*list);
			while (rev_iter->prev != (void *) 0)
			{
				if (rev_iter->n < rev_iter->prev->n)
				{
					swap_node(rev_iter->prev, rev_iter);
					if (rev_iter->prev == (void *) 0)
						*list = rev_iter;
					print_list(*list);
				} else
					break;
			}
		} else
			swapped = false;
		if (!swapped)
			curr_iter = curr_iter->next;
	}
}
