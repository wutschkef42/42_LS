/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:39:28 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/23 16:44:36 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static t_ls	init_ls(void)
{
	t_ls	ls;

	ls.options = 0;
	return (ls);
}

static int	is_option(char c)
{
	return (ft_strchr("Ralrt", c) ? 1 : 0);
}

static int	print_usage(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [-Raltr] [file...]\n");
	return (0);
}

static int	parse_flag(t_ls *ls, char *av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!is_option(av[i]))
		{
			print_usage(av[i]);
			exit(1);
		}
		if (av[i] == 'R')
			ls->options |= RC;
		else if (av[i] == 'a')
			ls->options |= AL;
		else if (av[i] == 'l')
			ls->options |= LO;
		else if (av[i] == 'r')
			ls->options |= RV;
		else if (av[i] == 't')
			ls->options |= TM;
	}
	return (1);
}

t_ls		parse(int ac, char **av, int *pos)
{
	t_ls	ls;

	ls = init_ls();
	*pos = 0;
	while (++(*pos) < ac && av[*pos][0] == '-' &&
		ft_strlen(av[*pos]) > 1)
		parse_flag(&ls, av[*pos]);

	return (ls);
}
