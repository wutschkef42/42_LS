

#include "libft.h"
#include "ft_ls.h"

void	ft_lstadd_sorted(t_list **alst, t_list *new)
{
    t_list  *tmp;
    t_ls    *ls;

    if (!alst)
        return ;
    if (!(*alst))
    {
        *alst = new;
        return ;
    }
    tmp = *alst;
    while (tmp->next)
    {
        ls = (t_ls*)(tmp->content);
        if (ft_strcmpc(((t_ls*)(new->content))->file, ((t_ls*)(tmp->content))->file) <= 0)
        {
            new->next = tmp->next;
            tmp->next = new;
            return ;
        }
        tmp = tmp->next;
    }
    tmp->next = new;
}
