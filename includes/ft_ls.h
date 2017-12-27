/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:44:11 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/23 16:51:59 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft.h"

#include <stdio.h>


#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

# define NO 0
# define RC 1
# define LO 2
# define AL 4
# define RV 8
# define TM 16


typedef struct	s_ls
{
	char			*file;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	long			time;
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
t_list	*to_list(char *dir, t_format *format);
void	ft_lstadd_sort(t_list **alst, t_list *new, int (*cmp)(t_list*, t_list*));
int		ft_strcmpc(const char *s1, const char *s2);


// print.c
int		print_stat(t_ls *ls, t_format *format);
int		print_basic(char *file);
void	print_list(t_list *files, int options, t_format *format);
void	print_format(t_format *format);

void	reverse_list(t_list **head);
void    reverse_list_rec(t_list **head);

#endif
