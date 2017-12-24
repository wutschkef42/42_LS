/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <fwutschk@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 06:08:39 by wutschkef         #+#    #+#             */
/*   Updated: 2017/06/17 06:09:21 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int			ft_putstr(const char *str, size_t len)
{
	write(1, str, len);
	return (len);
}

/*
void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
*/