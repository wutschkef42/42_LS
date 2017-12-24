/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <fwutschk@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 18:57:16 by wutschkef         #+#    #+#             */
/*   Updated: 2017/06/27 00:21:38 by fwutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_c;
	char	*dst_c;

	src_c = (char *)src;
	dst_c = (char *)dst;
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
