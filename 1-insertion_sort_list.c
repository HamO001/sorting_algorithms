#include "listint.h"
#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to a pointer to the head of the list.
 * @prev: A pointer to the previous node to be swapped.
 * @temp: A pointer to the current node to be swapped.
 *
 * This function swaps the positions of two nodes in a doubly linked list.
 * It updates the previous and next pointers of the nodes involved in the swap
 * and ensures that the list remains connected after the swap.
 *
 * @list: The address of the pointer to the head of
 * the list to reflect changes.
 * @prev: The node that precedes the 'temp' node.
 * @temp: The node to be swapped with its predecessor.
 */

void swap_nodes(listint_t **list, listint_t *prev, listint_t *temp)
{
	if (prev->prev != NULL)
	{
		prev->prev->next = temp;
	}
	if (temp->next != NULL)
	{
		temp->next->prev = prev;
	}

	prev->next = temp->next;
	temp->prev = prev->prev;

	prev->prev = temp;
	temp->next = prev;

	if (temp->prev == NULL)
	{
		*list = temp;
	}
	else
	{
		temp->prev->next = temp;
	}
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
      /* Swap the nodes */
			swap_nodes(list, prev, temp);
			print_list(*list); /* Print the list after each swap */
			prev = temp->prev;
		}

		current = current->next;
	}
}
