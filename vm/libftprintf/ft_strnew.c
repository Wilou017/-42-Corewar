/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:15:44 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/06 14:12:21 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dst;

	dst = (char *)ft_memalloc(size + 1);
	if (dst)
	{
		ft_memset(dst, '\0', size + 1);
		return (dst);
	}
	return (NULL);
}
