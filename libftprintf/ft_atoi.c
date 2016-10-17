/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:11:57 by amaitre           #+#    #+#             */
/*   Updated: 2016/03/05 17:50:21 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int nbr;
	int neg;
	int i;

	neg = 1;
	nbr = 0;
	i = 0;
	while (nptr[i] &&
		(nptr[i] == ' ' ||
			nptr[i] == '\n' ||
			nptr[i] == '\r' ||
			nptr[i] == '\t' ||
			nptr[i] == '\f' ||
			nptr[i] == '\v'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-' && (neg = -1))
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += (nptr[i++]) - 48;
	}
	return (neg * nbr);
}
