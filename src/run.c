/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:40:01 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:40:20 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	run(int ac, char **av)
{
	int		pos;
	int		options;

	pos = 0;
	options = parse_options(ac, av, &pos);
	if (pos == ac)
		ft_ls(options, ".");
	while (pos < ac)
	{
		ft_ls(options, av[pos]);
		pos++;
	}
	return (1);
}
