
#include "libft.h"

static void    rev_recurse(t_list **head, t_list *node)
{
    if (!(node->next))
    {
        *head = node;
        return ;
    }
    rev_recurse(head, node->next);
    node->next->next = node;
    node->next = NULL;
}

void            reverse_list_rec(t_list **head)
{
    if (*head == NULL)
        return ;
    rev_recurse(head, *head);
}

void            reverse_list(t_list **list)
{
    t_list  *prev, *cur, *next;

    if (!(*list))
        return ;
    prev = NULL;
    cur = *list;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *list = prev;
}