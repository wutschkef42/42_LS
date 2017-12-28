
#include "libft.h"
#include "ft_ls.h"

size_t	ft_numlen(unsigned long n)
{
	int	len;

	len = 0;
	while (++len && (n = n / 10));
	return (len);
}

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

char	*ft_strfjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}