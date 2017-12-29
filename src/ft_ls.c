/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:51:38 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:07:41 by wutschkef        ###   ########.fr       */
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

static t_format	*init_format(void)
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

static char		*get_path(char *dir, t_list *files)
{
	char	*path;

	path = ft_strfjoin(ft_strjoin(dir, "/"), ((t_ls*)(files->ct))->file);
	ft_printf("\n%s:\n", path);
	return (path);
}

int				ft_ls(int options, char *dir)
{
	t_list		*fls;
	t_list		*tmp;
	t_format	*format;
	char		*path;

	format = init_format();
	if (!(fls = to_list(dir, options, format)))
	{
		free(format);
		return (-1);
	}
	print_list(fls, options, format);
	free(format);
	tmp = fls;
	while ((options & RC) && fls)
	{
		if (S_ISDIR(((t_ls*)(fls->ct))->mode) && (nd(((t_ls*)(fls->ct))->file)))
		{
			path = get_path(dir, fls);
			ft_ls(options, path);
			free(path);
		}
		fls = fls->next;
	}
	return (clear_list(tmp));
}
