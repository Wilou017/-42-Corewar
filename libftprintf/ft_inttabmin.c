/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:27:03 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/14 13:48:34 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_inttabmin(int *tab, int size)
{
	int min;

	min = tab[0];
	while (--size >= 0)
	{
		if (tab[size] < min)
			min = tab[size];
	}
	return (min);
}
