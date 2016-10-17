/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:47:54 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/20 16:51:59 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	*ft_inttabjoin(int *tab1, int size1, int *tab2, int size2)
{
	int *ret;
	int i;
	int j;

	i = 0;
	j = 0;
	ret = ft_inttabnew(size1 + size2);
	while (i < size1)
	{
		ret[i] = tab1[i];
		i++;
	}
	while (j < size2)
		ret[i++] = tab2[j++];
	return (ret);
}
