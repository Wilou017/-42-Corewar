/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:18:29 by amaitre           #+#    #+#             */
/*   Updated: 2016/07/18 14:26:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(t_intmax n, int base)
{
	static char itoa_num[17] = "0123456789abcdef\0";
	char		*alpha;
	t_uintmax	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	alpha = ft_strnew(0);
	if (n < 0)
		nb = (base == 10) ? (t_uintmax)(-n) : ((t_uintmax)n);
	while (nb > 0)
	{
		alpha = ft_strjoin(alpha, ft_chartostr(itoa_num[nb % base], 1), 3);
		nb /= base;
	}
	(n < 0 && base == 10) ? (alpha = ft_strjoin(alpha, "-", 1)) : 0;
	ft_delcharinstr(&alpha, '0', 0);
	return (alpha);
}
