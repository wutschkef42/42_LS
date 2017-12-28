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



static void	update_format(t_ls *node, t_format *format)
{
	char	*owner;
	char	*group;

	owner = getpwuid(node->uid)->pw_name;
	group = getgrgid(node->gid)->gr_name;
	format->owner_width = ft_strlen(owner) > format->owner_width ?
		ft_strlen(owner) : format->owner_width;
	format->group_width = ft_strlen(group) > format->group_width ?
		ft_strlen(group) : format->group_width;
	format->nlink_width = ft_numlen(node->nlink) > format->nlink_width ?
		ft_numlen(node->nlink) : format->nlink_width;
	format->size_width = ft_numlen(node->size) > format->size_width ?
		ft_numlen(node->size) : format->size_width;
}

void	print_format(t_format *format)
{
	printf("owner_width: %ld, group_width: %ld, nlink_width: %ld, size_width: %ld\n",
		format->owner_width, format->group_width, format->nlink_width, format->size_width);
}





static void	*make_node(char *dir, char *file, t_format	*format)
{
	struct stat	fileStat;
	t_ls		*node;
	int			i;
	char		*tmp;
	
	tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);

	if (!(node = malloc(sizeof(t_ls))) ||
		lstat(tmp, &fileStat) < 0)
		return (NULL);
	free(tmp);
	if (!(node->file = malloc(sizeof(char) * ft_strlen(file) + 1)))
		return (NULL);
	node->link_ref = NULL;
	if (S_ISLNK(fileStat.st_mode))
	{
		i = 1;
		if (!(node->link_ref = ft_memalloc(sizeof(char) * LINK_REF_SIZE)))
			return (NULL);
		tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);
		readlink(tmp, node->link_ref, LINK_REF_SIZE);
		free(tmp);
		while ((node->link_ref)[LINK_REF_SIZE * i] != 0)
		{
			i++;
			free(node->link_ref);
			if (!(node->link_ref = ft_memalloc(sizeof(char) * LINK_REF_SIZE * i)))
				return (NULL);
			tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);
			readlink(tmp, node->link_ref, LINK_REF_SIZE * i);
			free(tmp);
		}
	}
	ft_strcpy(node->file, file);
	node->mode = fileStat.st_mode;
	node->nlink = fileStat.st_nlink;
	node->uid = fileStat.st_uid;
	node->gid = fileStat.st_gid;
	node->size = fileStat.st_size;
	node->time = fileStat.st_mtime;
	update_format(node, format);
	return ((void*)(node));
}



t_list	*to_list(char *dir, int options, t_format *format)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*files;
	void			*tmp;

	(void)options;
	files = NULL;
	//printf("ATTEMPT TO OPEN: %s\n", dir);
	if (!(dirp = opendir(dir)))
	{
		perror("couldn't open.");
		return (NULL);
	}
	dp = readdir(dirp);
	while (dp != NULL)
	{
		if (options & TM)	
		{
			tmp = make_node(dir,dp->d_name, format);
			ft_lstadd_sort(&files, ft_lstnew(tmp, sizeof(t_ls)), &comp_tstamp);
		}
 		else
		{
			tmp = make_node(dir,dp->d_name, format);
			ft_lstadd_sort(&files, ft_lstnew(tmp, sizeof(t_ls)), &comp_lex);	
		}
		free(tmp);
		dp = readdir(dirp);
	}
	if (options & RV)
		reverse_list(&files);
	if (errno != 0)
		perror("error reading directory.");
	closedir(dirp);
	return (files);
}

