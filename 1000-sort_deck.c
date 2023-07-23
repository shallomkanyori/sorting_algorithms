#include "deck.h"
#include <stdio.h>

int cmp_card_nodes(const void *a, const void *b);
int get_card_value(const card_t *card);

/**
 * sort_deck - sorts a deck of cards "A" to "K", Spades to Diamonds
 * @deck: pointer to a pointer to the head of the card list
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *card_nodes[52];
	deck_node_t *curr, *prev;
	int i;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	for (i = 0, curr = *deck; i < 52 && curr; i++, curr = curr->next)
		card_nodes[i] = curr;

	qsort(card_nodes, 52, sizeof(card_nodes[0]), cmp_card_nodes);

	*deck = card_nodes[0];
	prev = *deck;

	for (i = 1; i < 52; i++)
	{
		curr = card_nodes[i];
		prev->next = curr;
		curr->prev = prev;
		prev = curr;
	}

	curr->next = NULL;
}

/**
 * cmp_card_nodes - compares two card nodes
 * @a: pointer to a pointer to the node containing the first card
 * @b: pointer to a pointer to the node containing the second card
 *
 * Return: > 0 if card a > card b, 0 if the same, < 0 if card a < card b
 */
int cmp_card_nodes(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	const card_t *card_a = node_a->card;
	const card_t *card_b = node_b->card;

	int val_a = get_card_value(card_a);
	int val_b = get_card_value(card_b);

	return (val_a - val_b);
}

/**
 * get_card_value - returns the numeric value of a card
 * @card: a pointer to the card
 *
 * Return: the numeric value of @card, 500 if not a valid card
 */
int get_card_value(const card_t *card)
{
	char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"Jack", "Queen", "King"};

	int suit = card->kind * 100;
	int val;

	for (val = 0; val < 13; val++)
	{
		if (strcmp(card->value, ranks[val]) == 0)
			return (suit + val);
	}

	return (500);
}
