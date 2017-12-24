/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 21:36:22 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/23 21:36:24 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	print_stat(char	*file)
{
	struct stat fileStat;

	if (stat(file, &fileStat) < 0)
		return (1);
	ft_printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	ft_printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	ft_printf( "  %2d", (fileStat.st_nlink));
	ft_printf( " %s", getpwuid(fileStat.st_uid)->pw_name);
	ft_printf( "  %s", getgrgid(fileStat.st_gid)->gr_name);
	ft_printf( "  %5d", (fileStat.st_size));
	ft_printf( " %s", (ft_strsub(ctime(&fileStat.st_mtime), 4, 12)));
	ft_printf( " %s", file);
	ft_printf("\n");
	return (0);
}

int	ft_ls(t_ls ls, char *dir)
{
	DIR				*dirp;
	struct dirent	*dp;

	if (!(dirp = opendir(dir)))
	{
		perror("couldn't open.");
		return (1);
	}
	while (dp)
	{
		if ((dp = readdir(dirp)))
		{
			//ft_printf("%s\n", dp->d_name);
			print_stat(dp->d_name);
		}
			
			
	}	
	if (errno != 0)
		perror("error reading directory.");
	else
		(void)closedir(dirp);
	return (0);
}


