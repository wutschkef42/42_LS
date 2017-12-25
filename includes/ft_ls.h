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
	int				time;
}				t_ls;

int		run(int ac, char **av);
int		parse_options(int ac, char **av, int *pos);
int		ft_ls(int options, char *dir);
int		print_stat(char	*file);
t_list	*to_list(char *dir);
void	ft_lstadd_sorted(t_list **alst, t_list *new);
int		ft_strcmpc(const char *s1, const char *s2);

#endif
