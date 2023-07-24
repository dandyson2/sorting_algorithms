#include "sort.h"

/**
* nodes_swap - Function that swaps two nodes in a
* double linked list
* @head: Ptr to the head of double linked list
* @node1: First node to swap
* @node2: Second node to swap
*/
void nodes_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
(*node1)->next = node2->next;

if (node2->next != NULL)
node2->next->prev = *node1;

node2->prev = (*node1)->prev;

node2->next = *node1;

if ((*node1)->prev != NULL)
(*node1)->prev->next = node2;
else
*head = node2;

(*node1)->prev = node2;

*node1 = node2->prev;
}


/**
* insertion_sort_list - Function that sorts a
* double linked list of integers in ascending order
* using insertion sort algorithm
* @list: Ptr to the head of double linked list
*/

void insertion_sort_list(listint_t **list)
{
listint_t *iter, *insert, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

iter = (*list)->next;
while (iter != NULL)
{
tmp = iter->next;
insert = iter->prev;

while (insert != NULL && iter->n < insert->n)
{
nodes_swap(list, &insert, iter);
print_list((const listint_t *)*list);
insert = iter->prev;
}

iter = tmp;
}
}
