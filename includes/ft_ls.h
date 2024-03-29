/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:44:11 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:08:40 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

# define NO 0
# define RC 1
# define LO 2
# define AL 4
# define RV 8
# define TM 16

# define LINK_REF_SIZE 100

typedef int (*t_compare)(t_list*, t_list*);


typedef struct	s_ls
{
	char			*file;
	char			*link_ref;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	long			time;
	long			time_nsec;
	long			bsize;
}				t_ls;

typedef struct	s_format
{
	size_t	owner_width;
	size_t	group_width;
	size_t	nlink_width;
	size_t	size_width;
}				t_format;

int		run(int ac, char **av);
int		parse_options(int ac, char **av, int *pos);
int		ft_ls(int options, char *dir);

t_list		*to_list(char *dir, int options, t_format *format);
int			clear_list(t_list *files);
void		ft_lstadd_sort(t_list **alst, t_list *new, int (*cmp)(t_list*, t_list*));
int			comp_lex(t_list *a, t_list *b);
int			comp_tstamp(t_list *a, t_list *b);
void		reverse_list(t_list **head);
int			print_stat(t_ls *ls, t_format *format);
int			print_basic(char *file);
void		print_list(t_list *files, int options, t_format *format);
void		print_format(t_format *format);
int			nd(char *file);
int			not_dot_file(char *file);
size_t		ft_numlen(unsigned long n);
char		*ft_strfjoin(char const *s1, char const *s2);
void		call_blocksize(int options, t_list *files);
int			print_blocksize(t_list *files, int options);
int			is_dir(char *path);
t_compare	choose_sort(int options);




#endif
