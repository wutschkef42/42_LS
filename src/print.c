
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

int	print_stat(t_ls	*ls, t_format *format)
{
    (void)format;
	ft_printf( (S_ISDIR(ls->mode)) ? "d" : "-");
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
	ft_printf("\n");
	return (0);
}

int	print_basic(char *file)
{
	ft_printf("%s ", file);
	return (0);
}

void	print_list(t_list *files, int options, t_format *format)
{
	t_ls *ls;

	if (options & RV)
		reverse_list_rec(&files);
	while (files)
	{
		ls = (t_ls*)(files->content);

     	if (options & LO)
        	print_stat(ls, format);
		else
			print_basic(ls->file);
		//printf("name: %s, mode: %d, nlink: %d, uid: %u, gid: %u, size: %lld, time: %d\n", 
		//ls->file, ls->mode, ls->nlink, ls->uid, ls->gid, ls->size, ls->time);
		files = files->next;
	}
}