#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
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

void print_array(const int *, unsigned int);
void print_list(const listint_t *);
void bubble_sort(int *, unsigned int);
void swap(int *, int *);
void swap_node(listint_t *, listint_t *);
void insertion_sort_list(listint_t **);
#endif
