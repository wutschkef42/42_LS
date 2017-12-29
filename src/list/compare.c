/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:11:19 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:12:28 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		comp_lex(t_list *a, t_list *b)
{
	return (ft_strcmp(((t_ls*)(a->ct))->file,
		((t_ls*)(b->ct))->file));
}

int		comp_tstamp(t_list *a, t_list *b)
{
	if (((t_ls*)(a->ct))->time <
		((t_ls*)(b->ct))->time)
		return (1);
	else if (((t_ls*)(a->ct))->time >
		((t_ls*)(b->ct))->time)
		return (-1);
	else if (((t_ls*)(a->ct))->time_nsec <
		((t_ls*)(b->ct))->time_nsec)
		return (1);
	else if (((t_ls*)(a->ct))->time_nsec >
		((t_ls*)(b->ct))->time_nsec)
		return (-1);
	else
		return (comp_lex(a, b));
}
