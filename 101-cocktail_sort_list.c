#include "sort.h"

/**
 * _node_replace - Function that swaps a node in
 * a double-linked list
 * @list: Ptr to the head of double-linked list
 * @back: Ptr to the tail of double-linked list
 * @current: Ptr to the swapping node
 */

void _node_replace(listint_t **list, listint_t **back, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*back = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}

/**
 * _node_replace_t - Function that swaps a node in
 * a double-linked list
 * @list: Ptr to the head of double-linked list
 * @back: Ptr to the tail of double-linked list
 * @current: Ptr to the current swapping node
 */

void _node_replace_t(listint_t **list, listint_t **back, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*back = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}

/**
 * cocktail_sort_list - Function that sorts a double linked list
 * of integers in ascending order using the Cocktail shaker sort algorithm
 * @list: Ptr to the head of double-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *back, *current;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (back = *list; back->next != NULL;)
		back = back->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (current = *list; current != back; current = current->next)
		{
			if (current->n > current->next->n)
			{
				_node_replace(list, &back, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				_node_replace_t(list, &back, &current);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
