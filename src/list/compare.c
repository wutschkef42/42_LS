
#include "libft.h"
#include "ft_ls.h"

int		comp_lex(t_list *a, t_list *b)
{
	return (ft_strcmp(((t_ls*)(a->content))->file,
		((t_ls*)(b->content))->file));
}

int		comp_tstamp(t_list *a, t_list *b)
{
	if (((t_ls*)(a->content))->time <
		((t_ls*)(b->content))->time)
		return (1);
	else if (((t_ls*)(a->content))->time >
		((t_ls*)(b->content))->time)
		return (-1);
	return (0);
}