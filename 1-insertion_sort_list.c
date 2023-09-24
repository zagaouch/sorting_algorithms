#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *sorted = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return; 

    while (*list != NULL)
    {
        listint_t *current = *list;
        *list = current->next;

        if (sorted == NULL || current->n <= sorted->n)
        {
         
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            
            listint_t *tmp = sorted;
            while (tmp->next != NULL && tmp->next->n < current->n)
                tmp = tmp->next;

          
            current->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->prev = current;
            tmp->next = current;
            current->prev = tmp;
        }

        if (current->prev == NULL)
            *list = sorted;
        print_list(*list);
    }
}
