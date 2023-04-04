#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to pointer to the first node of the list
 * @idx: index where the new node should be added (starting at 0)
 * @n: value to be stored in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 **/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *current;
    unsigned int i;

    if (head == NULL)  /* if head is NULL, the list is empty */
        return NULL;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)  /* if malloc fails, return NULL */
        return NULL;

    new_node->n = n;

    if (idx == 0) {  /* special case: insert at the beginning */
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current = *head;
    for (i = 0; i < idx - 1; i++) {  /* find the node before the insertion point */
        if (current == NULL || current->next == NULL)
            return NULL;  /* if the index is out of bounds, return NULL */
        current = current->next;
    }

    new_node->next = current->next;  /* insert the new node */
    current->next = new_node;

    return new_node;
}
