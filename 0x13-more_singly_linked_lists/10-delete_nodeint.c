#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at a given position
 * @head: pointer to pointer to the first node of the list
 * @index: index of the node to be deleted (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 **/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *temp;
    unsigned int i;

    if (head == NULL || *head == NULL)  /* if head is NULL, the list is empty */
        return -1;

    if (index == 0) {  /* special case: delete the first node */
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    current = *head;
    for (i = 0; i < index - 1; i++) {  /* find the node before the deletion point */
        if (current == NULL || current->next == NULL)
            return -1;  /* if the index is out of bounds, return -1 */
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
        return -1;  /* if the index is out of bounds, return -1 */

    temp = current->next;  /* delete the node */
    current->next = temp->next;
    free(temp);

    return 1;
}
