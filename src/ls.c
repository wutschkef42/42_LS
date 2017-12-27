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

int	not_dot(char *file)
{
	if (ft_strcmp(file, ".") != 0 && ft_strcmp(file, "..") != 0)
		return (1);
	return (0);
}

int	ft_ls(int options, char *dir)
{
	t_list		*files;
	t_format	*format;

	format = init_format();
	files = to_list(dir, options, format);
	print_list(files, options, format);
	while ((options & RC) && (files = files->next))
	{
		if (S_ISDIR(((t_ls*)(files->content))->mode) && (not_dot(((t_ls*)(files->content))->file)))
			ft_ls(options, ft_strjoin(ft_strjoin(dir, "/"), ((t_ls*)(files->content))->file));
	}
	return (0);
}


