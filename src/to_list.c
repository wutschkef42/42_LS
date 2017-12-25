/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 12:41:51 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/24 12:41:53 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <errno.h>
#include <dirent.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static void	*make_node(char *dir, char *file)
{
	struct stat	fileStat;
	t_ls		*node;

	if (!(node = malloc(sizeof(t_ls))) ||
		stat(ft_strjoin(ft_strjoin(dir, "/"), file), &fileStat) < 0)
		return (NULL);
	if (!(node->file = malloc(sizeof(char) * ft_strlen(file) + 1)))
		return (NULL);
	ft_strcpy(node->file, file);
	node->mode = fileStat.st_mode;
	node->nlink = fileStat.st_nlink;
	node->uid = fileStat.st_uid;
	node->gid = fileStat.st_gid;
	node->size = fileStat.st_size;
	node->time = fileStat.st_mtime;
	return ((void*)(node));
}

t_list	*to_list(char *dir)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*files;

	files = NULL;
	if (!(dirp = opendir(dir)))
	{
		perror("couldn't open.");
		return (NULL);
	}

	dp = readdir(dirp);
	while (dp != NULL)
	{	
		printf("%s\n", dp->d_name);
		ft_lstadd(&files, ft_lstnew(make_node(dir, dp->d_name), sizeof(t_ls)));
 		dp = readdir(dirp);
	}
	if (errno != 0)
		perror("error reading directory.");
	else
		(void)closedir(dirp);
	return (files);
}