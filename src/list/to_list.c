/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 12:41:51 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:33:49 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static t_ls	*update_format(t_ls *node, t_format *format)
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
	return (node);
}

static void	handle_links(t_ls **node, char *dir, char *file)
{
	int		i;
	char	*tmp;

	i = 1;
	if (!((*node)->link_ref = ft_memalloc(sizeof(char) * LINK_REF_SIZE)))
		return ;
	tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);
	readlink(tmp, (*node)->link_ref, LINK_REF_SIZE);
	free(tmp);
	while (((*node)->link_ref)[LINK_REF_SIZE * i] != 0)
	{
		i++;
		free((*node)->link_ref);
		if (!((*node)->link_ref = ft_memalloc(sizeof(char) *
			LINK_REF_SIZE * i)))
			return ;
		tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);
		readlink(tmp, (*node)->link_ref, LINK_REF_SIZE * i);
		free(tmp);
	}
}

static void	*make_node(char *dir, char *file, t_format *format)
{
	struct stat	file_stat;
	t_ls		*node;
	char		*tmp;

	tmp = ft_strfjoin(ft_strjoin(dir, "/"), file);
	if (lstat(tmp, &file_stat) < 0)
		return (NULL);
	if (!(node = malloc(sizeof(t_ls))))
		return (NULL);
	free(tmp);
	if (!(node->file = malloc(sizeof(char) * ft_strlen(file) + 1)))
		return (NULL);
	node->link_ref = NULL;
	if (S_ISLNK(file_stat.st_mode))
		handle_links(&node, dir, file);
	ft_strcpy(node->file, file);
	node->mode = file_stat.st_mode;
	node->nlink = file_stat.st_nlink;
	node->uid = file_stat.st_uid;
	node->gid = file_stat.st_gid;
	node->size = file_stat.st_size;
	node->time = file_stat.st_mtimespec.tv_sec;
	node->time_nsec = file_stat.st_mtimespec.tv_nsec;
	node->bsize = file_stat.st_blocks;
	return ((void*)(update_format(node, format)));
}

int			opendir_error(struct dirent **dp, char *dir, DIR **dirp)
{
	if (!(is_dir(dir)) || !(*dirp = opendir(dir)))
	{
		perror("couldn't open.");
		return (1);
	}
	*dp = readdir(*dirp);
	return (0);
}

t_list		*to_list(char *dir, int options, t_format *format)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_list			*files;
	void			*tmp;

	files = NULL;
	if (opendir_error(&dp, dir, &dirp))
		return (NULL);
	while (dp != NULL)
	{
		if (!(tmp = make_node(dir, dp->d_name, format)))
			return (NULL);
		ft_lstadd_sort(&files, ft_lstnew(tmp, sizeof(t_ls)),
			choose_sort(options));
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
