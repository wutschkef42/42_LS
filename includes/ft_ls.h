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

#include <stdio.h>

# define NO 0
# define RC 1
# define LO 2
# define AL 4
# define RV 8
# define TM 16

typedef struct	s_ls
{
	int	options;
}				t_ls;

int		run(int ac, char **av);
t_ls	parse(int ac, char **av, int *pos);
int		ft_ls(t_ls ls, char *dir);
int		print_stat(char	*file);

#endif
