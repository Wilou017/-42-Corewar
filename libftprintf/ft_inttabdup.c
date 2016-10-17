/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:01:49 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/20 14:59:09 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		*ft_inttabdup(int *tab, int size)
{
	int *res;

	res = ft_inttabnew(size);
	while (tab && --size >= 0)
		res[size] = tab[size];
	return (res);
}
