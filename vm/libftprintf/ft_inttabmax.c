/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:27:03 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/14 13:48:28 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_inttabmax(int *tab, int size)
{
	int max;

	max = tab[0];
	while (--size >= 0)
	{
		if (tab[size] > max)
			max = tab[size];
	}
	return (max);
}
