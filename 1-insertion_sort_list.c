#include "sort.h"
/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 * @list: list of integer
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *current = *list;

	if (*list == NULL)
		return;
	while (current)
	{
		current = current->next;
		while (temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
		temp = current;
	}
}
