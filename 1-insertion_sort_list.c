#include "sort.h"

/**
 * insertion_sort_list - Sorts integers in ascending order
 *
 * @list: array of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		temp = current;

		while (temp->prev != NULL && temp->prev->n > current->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				(*list) = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}

		current = next;
	}
}
