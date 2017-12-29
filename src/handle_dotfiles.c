/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dotfiles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wutschkef <felix.wutschke@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:09:33 by wutschkef         #+#    #+#             */
/*   Updated: 2017/12/28 19:09:49 by wutschkef        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		not_dot_file(char *file)
{
	if (*file != '.')
		return (1);
	return (0);
}

int		nd(char *file)
{
	if (ft_strcmp(file, ".") != 0 && ft_strcmp(file, "..") != 0)
		return (1);
	return (0);
}
