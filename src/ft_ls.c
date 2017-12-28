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


// replace init function by passing compound literal to to_list()
static t_format	*init_format()
{
	t_format	*format;

	if (!(format = malloc(sizeof(t_format))))
		return (NULL);
	format->owner_width = 0;
	format->group_width = 0;
	format->nlink_width = 0;
	format->size_width = 0;
	return (format);
}


int	ft_ls(int options, char *dir)
{
	t_list		*files;
	t_list		*tmp;
	t_format	*format;
	char		*path, *path2;

	format = init_format();
	if (!(files = to_list(dir, options, format)))
	{
		free(format);
		return (-1);
	}
		
	print_list(files, options, format);
	free(format);
	tmp = files;
// 	ft_printf("\n%s:\n", dir);
	while ((options & RC) && files)
	{
		printf("-------%s\n", (((t_ls*)(files->content))->file));
		if (S_ISDIR(((t_ls*)(files->content))->mode) && (not_dot_dir(((t_ls*)(files->content))->file)))
		{
			//ft_printf("----------recursive Call: %s\n", ((t_ls*)(files->content))->file);
			path2 = ft_strjoin(dir, "/");
			path = ft_strfjoin(path2, ((t_ls*)(files->content))->file);
			ft_ls(options, path);
			free(path);
		}	
		 files = files->next;	
	}
	clear_list(tmp);
	return (0);
}


