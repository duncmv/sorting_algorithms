#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: doubly-linked list
 * @curr: node currently indexed
 * @prev: node before curr
*/
void swap_nodes(listint_t **list, listint_t *curr, listint_t *prev)
{
	listint_t *temp;

	if (prev->prev != NULL)
		prev->prev->next = curr;
	if (curr->next != NULL)
		curr->next->prev = prev;

	temp = prev->prev;
	prev->prev = curr;
	prev->next = curr->next;
	curr->prev = temp;
	curr->next = prev;
	if (temp == NULL)
		*list = curr;

}
/**
 * insertion_sort_list - sorts a linked list using insertion sort algorithm
 * @list: double pointer to a linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *prev = *list;
	int i = 0;
	listint_t *stop;

	/*case when the list is empty or has one node*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		i = 0; /*tracks position of first swap in each iteration*/
		stop = curr;
swap:
		if (prev != NULL && curr->n < prev->n)
		{
			swap_nodes(list, curr, prev);
			print_list(*list);
			++i;
			if (i == 1)
				stop = prev;
		}
		else
		{
			curr = stop->next;
			if (curr != NULL)
				prev = curr->prev;
			continue;
		}
		prev = curr->prev;
		goto swap;
	}
}
