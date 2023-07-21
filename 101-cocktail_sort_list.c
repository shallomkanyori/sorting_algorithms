#include "sort.h"

void swap(listint_t *node, listint_t *prev, listint_t **head);

/**
 * cocktail_sort_list - cocktail shaker sorts a doubly linked integer list
 * @list: a pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		curr = *list;
		swapped = 0;

		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap(curr->next, curr, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				curr = curr->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		while (curr->prev)
		{
			if (curr->prev->n > curr->n)
			{
				swap(curr, curr->prev, list);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				curr = curr->prev;
			}
		}
	}
}

/**
 * swap - swaps two consecutive nodes in a doubly linked list
 * @node: the current node
 * @prev: the previous node
 * @head: a pointer to a pointer to the head of the list
 */
void swap(listint_t *node, listint_t *prev, listint_t **head)
{
	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;

	node->prev = prev->prev;
	if (prev->prev)
		prev->prev->next = node;
	else
		*head = node;

	prev->prev = node;
	node->next = prev;
}
