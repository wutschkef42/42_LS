/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 21:17:00 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 21:17:03 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_compare	choose_sort(int options)
{
	int	(*cmp)(t_list*, t_list*);

	if (options & TM)
		cmp = &comp_tstamp;
	else
		cmp = &comp_lex;
	return (cmp);
}
