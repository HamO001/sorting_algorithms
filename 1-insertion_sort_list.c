#include "listint.h"
#include "sort.h"
#include <stdio.h>

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

					print_list(*list); /* Print the list after each swap */

					prev = temp->prev;
		}

		current = current->next;
	}
}
