/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:39:28 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:35:19 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

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

static int	parse_option(int *options, char *av)
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
			*options |= RC;
		else if (av[i] == 'a')
			*options |= AL;
		else if (av[i] == 'l')
			*options |= LO;
		else if (av[i] == 'r')
			*options |= RV;
		else if (av[i] == 't')
			*options |= TM;
	}
	return (1);
}

int			parse_options(int ac, char **av, int *pos)
{
	int		options;

	options = 0;
	*pos = 0;
	while (++(*pos) < ac && av[*pos][0] == '-' &&
		ft_strlen(av[*pos]) > 1)
		parse_option(&options, av[*pos]);
	return (options);
}
