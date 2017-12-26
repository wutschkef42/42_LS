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
	t_format	*format;

	format = init_format();
	files = to_list(dir, format);
	print_list(files, options, format);
	return (0);
}


