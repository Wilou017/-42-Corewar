/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:08:26 by amaitre           #+#    #+#             */
/*   Updated: 2015/11/30 17:01:33 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			n2;
	unsigned char	*c1;
	unsigned char	*c2;

	n2 = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n2 < n)
	{
		if (c1[n2] != c2[n2])
			return (c1[n2] - c2[n2]);
		n2++;
	}
	return (0);
}
