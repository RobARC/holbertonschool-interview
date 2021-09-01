#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome- function that check if a linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *adv = NULL, *beh = NULL;
	unsigned int pos = 0, lenght = 0, i = 0;

	adv = *head;
	while (adv)
	{
		adv = adv->next;
		lenght++;
	}
	beh = *head;
	while (pos != lenght / 2)
	{
		adv = *head;
		if (pos != 0)
			beh = beh->next;
		for (i = 0; i < lenght - (pos + 1); i++)
			adv = adv->next;
		if (adv->n != beh->n)
			return (0);
		pos++;
	}
	return (1);
}
