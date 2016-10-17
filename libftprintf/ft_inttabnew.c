/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 20:15:44 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/06 19:35:20 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_inttabnew(size_t size)
{
	int *dst;
	int i;

	dst = (int *)malloc(sizeof(int) * (size + 1));
	if (dst)
	{
		i = size + 1;
		while (--i >= 0)
			dst[i] = -1;
		return (dst);
	}
	return (NULL);
}
