#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 * @list: A pointer to a pointer to the head of the list.
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
		return;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		current = *list;
			while (current->next != NULL)
			{
				if (current->n > current->next->n)
				{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
				}
				else
				current = current->next;
			}
			if (!swapped)
			break;
			swapped = 0;
			current = current->prev;
			while (current->prev != NULL)
			{
				if (current->n < current->prev->n)
				{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
				}
				else
				current = current->prev;
			}
	}
}