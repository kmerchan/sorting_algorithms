#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of ints with insertion sort
 * doubly linked list is sorted in ascending order
 * @list: pointer to head of listint_t doubly linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *mover = NULL, *previous = NULL, *place_holder = NULL;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	previous = (*list);
	if (previous->next)
		mover = previous->next;
	while (mover)
	{
		previous = mover->prev;
		place_holder = previous;
		while (mover->n < previous->n)
		{
			previous->next = mover->next;
			mover->prev = previous->prev;
			if (previous->prev)
				previous->prev->next = mover;
			if (mover->next)
				mover->next->prev = previous;
			mover->next = previous;
			previous->prev = mover;
			if (mover->prev)
				previous = mover->prev;
			else
			{
				(*list) = mover;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		if (mover->n < place_holder->n)
			mover = place_holder->next;
		else if (place_holder->next)
			mover = place_holder->next->next;
		else
			mover = place_holder->next;
	}
}
