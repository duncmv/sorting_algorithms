#include "sort.h"

/**
 * swap_func - fnction
 * @list : linked list
 * @neext : next to current code
 * @current : current node
 */
void swap_func(listint_t *current, listint_t **list, listint_t *neext)
{
	listint_t *temp;

	temp = current->prev;
	current->next = neext->next;
	if (neext->next)
		neext->next->prev = current;
	current->prev = neext;
	neext->next = current;
	neext->prev = temp;
	if (temp)
		temp->next = neext;
	else
		*list = neext;
	print_list(*list);
}
/**
 * swap_prev - function
 * @list : linked list
 * @previous : back to current node
 * @current : current node
 */
void swap_prev(listint_t *current, listint_t **list, listint_t *previous)
{
	listint_t *temp;

	temp = previous->prev;
	previous->next = current->next;
	if (current->next)
		current->next->prev = previous;
	previous->prev = current;
	current->next = previous;
	current->prev = temp;
	print_list(*list);
}

