/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:11:03 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 21:54:06 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_inttabsorted(int *tab, int size)
{
	int i;
	int rev;

	i = -1;
	rev = 0;
	while (++i < size - 1)
		if (tab[i] > tab[i + 1])
		{
			rev = 1;
			break ;
		}
	i = -1;
	while (++i < size - 1)
		if (tab[i] < tab[i + 1])
		{
			if (rev)
				return (0);
			rev = -1;
			break ;
		}
	return (rev);
}
