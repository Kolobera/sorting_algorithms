#include "sort.h"

/**
 * insertion_sort_list - sorting algorithm
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *next_node = NULL;
    
    if (list == NULL || *list == NULL || (*list)->next == NULL)
    {
        return;
    }
    next_node = (*list)->next;
    while (next_node)
    {
        while (next_node->prev && next_node->n < next_node->prev->n)
        {
            next_node->prev->next = next_node->next;
            if (next_node->next != NULL)
            {
                next_node->next->prev = next_node->prev;
            }
            next_node->next = next_node->prev;
            next_node->prev = next_node->prev->prev;
            next_node->next->prev = next_node;
            if (next_node->prev == NULL)
            {
                *list = next_node;
            }
            else
            {
                next_node->prev->next = next_node;
            }
            print_list(*list);
        }
        next_node = next_node->next;
    }
}
