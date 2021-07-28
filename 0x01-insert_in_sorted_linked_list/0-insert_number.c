#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node, function that insert a new node in number position .
 * @head pointer to the structure listin_t
 * @number:data of node
 * Return: node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newnode, *aux;
	int i, count = 0;
	newnode = *head;

	if (newnode == NULL)
		return (NULL);

	newnode = malloc(sizeof(struct listint_s)); /*creating newnode*/
		
	if (newnode == NULL)
	{
		free_listint(newnode);
		return (NULL);
	}

	/*asigned data to newnode*/
	newnode->n = number;
	newnode->next = NULL;

	aux = *head;

	/*crating a counter to know how much nodes are*/
	while (aux != NULL)
	{
		count++;
		aux = aux->next;
	}
	aux = *head;
	for (i = 0;  i < count; i++)
	{
		if (aux != NULL)
		{
			if (newnode->n >= aux->n && newnode->n >= aux->next->n)
			{
				aux = aux->next;
			}
			else
			{
				newnode->next = aux->next;
				aux->next = newnode;
				return(newnode);
			}	
		}
	}
	return (NULL);
}