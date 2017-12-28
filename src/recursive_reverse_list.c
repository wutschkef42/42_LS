
#include "libft.h"

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