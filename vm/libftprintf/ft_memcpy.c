/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:08:18 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/03 11:57:06 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest2;
	unsigned char *src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (n-- > 0)
		*dest2++ = *src2++;
	return (dest);
}
