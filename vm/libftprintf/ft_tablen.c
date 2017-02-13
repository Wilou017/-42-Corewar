/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:42:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/20 18:41:28 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tablen(char **tab, int full)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (tab)
		while (tab[i])
		{
			len += ft_strlen(tab[i]);
			i++;
		}
	if (full)
		return (len);
	return (i);
}
