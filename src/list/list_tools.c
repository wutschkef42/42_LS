

#include "ft_ls.h"
#include "libft.h"


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
        if ((*cmp)(cur, new) > 0)
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

static void	clear_ls(t_ls *ls)
{
	free(ls->file);
	free(ls->link_ref);
	free(ls);
}

void		clear_list(t_list *files)
{
	t_list	*tmp;

	while (files)
	{
		tmp = files->next;
		clear_ls((t_ls*)(files->content));
		free(files);
		files = tmp;
	}
}
