
#include "ft_ls.h"
#include "libft.h"

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
