/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:27:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/12 12:20:47 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <newlibft.h>

int	ft_min(int nbarg, ...)
{
	va_list		ap;
	int			i;
	int			min;
	int			tmp;

	i = nbarg;
	if (nbarg <= 0)
		return (0);
	va_start(ap, nbarg);
	min = va_arg(ap, int);
	while (i-- > 1)
	{
		tmp = va_arg(ap, int);
		if (tmp < min)
			min = tmp;
	}
	va_end(ap);
	return (min);
}
