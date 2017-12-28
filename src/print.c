
#include <errno.h>
#include <dirent.h>

#include "libft.h"
#include "ft_ls.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void	print_filetype(t_ls *ls)
{
	if (S_ISDIR(ls->mode))
		ft_printf("d");
	else if (S_ISLNK(ls->mode))
		ft_printf("l");
	else
		ft_printf("-");
}

int	print_stat(t_ls	*ls, t_format *format)
{	
	print_filetype(ls);
	ft_printf( (ls->mode & S_IRUSR) ? "r" : "-");
	ft_printf( (ls->mode & S_IWUSR) ? "w" : "-");
	ft_printf( (ls->mode & S_IXUSR) ? "x" : "-");
	ft_printf( (ls->mode & S_IRGRP) ? "r" : "-");
	ft_printf( (ls->mode & S_IWGRP) ? "w" : "-");
	ft_printf( (ls->mode & S_IXGRP) ? "x" : "-");
	ft_printf( (ls->mode & S_IROTH) ? "r" : "-");
	ft_printf( (ls->mode & S_IWOTH) ? "w" : "-");
	ft_printf( (ls->mode & S_IXOTH) ? "x" : "-");
	ft_printf( "  %*d", format->nlink_width, (ls->nlink));
	ft_printf( " %-*s", format->owner_width, getpwuid(ls->uid)->pw_name);
	ft_printf( "  %-*s", format->group_width, getgrgid(ls->gid)->gr_name);
	ft_printf( "  %*d", format->size_width, (ls->size));
	ft_printf( " %s", (ft_strsub(ctime(&ls->time), 4, 12)));
	ft_printf( " %s", ls->file);
	if (S_ISLNK(ls->mode))
		ft_printf(" -> %s", ls->link_ref);
	return (0);
}

int		print_basic(char *file)
{
	ft_printf("%s\n", file);
	return (0);
}

void	print_list(t_list *files, int options, t_format *format)
{
	t_ls *ls;

	while (files)
	{
		ls = (t_ls*)(files->content);

     	if (options & LO)
     	{
			if ((options & AL) || not_dot_file(ls->file))
			{
				print_stat(ls, format);
				if (files->next)
					ft_printf("\n");
			}	
     	}	
		else
		{
			if ((options &  AL) || not_dot_file(ls->file))
				print_basic(ls->file);
		}
		files = files->next;
	}
	//ft_printf("\n");
}