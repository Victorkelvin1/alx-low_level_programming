#include <stdio.h>
#include <stdlib.h>

/* Definition of a linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to delete the head node of a linked list */
int pop_listint(listint_t **head)
{
    int data = 0; /* Initialize data to be returned */
    listint_t *temp; /* Temporary node pointer */

    if (*head == NULL) { /* Check if list is empty */
        return 0;
    }

    data = (*head)->n; /* Get the data of the head node */
    temp = (*head)->next; /* Save the next node */
    free(*head); /* Free the head node */
    *head = temp; /* Update the head to the next node */

    return data; /* Return the data of the old head node */
}

