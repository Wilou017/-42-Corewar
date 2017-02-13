/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intinarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:09:39 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/19 22:19:17 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_intinarray(int *tab, int nb, int tabsize)
{
	int i;

	i = 0;
	while (i < tabsize)
	{
		if (nb == tab[i])
			return (1);
		i++;
	}
	return (0);
}
