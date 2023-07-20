#include "sort.h"

void swap(listint_t *node, listint_t *prev, listint_t **head);

/**
 * insertion_sort_list - insertion sorts a doubly linked integer list
 * @list: a pointer to a pointer to the head of the doubly linked integer list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *head, *next;

	if (list == NULL || *list == NULL)
		return;

	head = *list;
	curr = head->next;

	while (curr)
	{
		next = curr->next;

		if (curr->n >= curr->prev->n)
		{
			curr = curr->next;
			continue;
		}

		while (curr->prev)
		{
			if (curr->n >= curr->prev->n)
				break;

			swap(curr, curr->prev, &head);
			print_list(head);
		}

		curr = next;
	}

	*list = head;
}

/**
 * swap - swaps two consecutive nodes in a doubly linked list
 * @node: a pointer to the current node
 * @prev: a pointer to the previous node
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
