#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - function that insert a new node in number position .
* @head: pointer to the structure listin_t
* @number:data of node
* Return: newnode or NULL
*/

listint_t *insert_node(listint_t **head, int number)
{
	
	listint_t *newnode = NULL, *aux = NULL;

	if (*head == NULL)
		return (NULL);

	newnode = malloc(sizeof(struct listint_s)); /*creating newnode*/
	if (newnode == NULL)
	{
		free_listint(newnode);
		return (NULL);
	}
	newnode->n = number;
	newnode->next = NULL;
	aux = *head;
	
		if (aux->next == NULL)
		{
			*head = newnode;
			return (newnode);
		}
		else
		{
			while (aux != NULL)
			{
				if (newnode->n >= aux->n && aux->next != NULL)
				aux = aux->next;
				else
				{
					newnode->next = aux->next;
					aux->next = newnode;
					return (newnode);
				}
			}
			return (NULL);
		}
}
