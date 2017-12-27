

#include "libft.h"
#include "ft_ls.h"

void	ft_lstadd_sort(t_list **alst, t_list *new, int (*cmp)(t_list*, t_list*))
{
    t_list  *cur;
    t_list  *prev;

    if (!alst)
        return ;
    if (!(*alst))
    {
        *alst = new;
        return ;
    }
    prev = NULL;
    cur = *alst;
    while (cur)
    {
        if ((*cmp)(cur, new) >= 0)
        {
            new->next = cur;
            if (prev)
                prev->next = new;
            else
                *alst = new;
            return ;
        }
        prev = prev ? prev->next : *alst;
        cur = cur->next;
    }
    prev->next = new;
}
