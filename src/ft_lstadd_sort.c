

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
    if ((*cmp)(*alst, new) > 0)
    {
        new->next = *alst;
        *alst = new;
        return ;
    }
    prev = *alst;
    cur = (*alst)->next;
    while (cur)
    {
        if ((*cmp)(cur, new) >= 0)
        {
            new->next = cur;
            prev->next = new;
            return ;
        }
        prev = prev->next;
        cur = cur->next;
    }
    prev->next = new;
}
