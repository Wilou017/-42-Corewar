/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:39:57 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/28 16:57:50 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countchar(const char *s, char c)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	if (s && c)
	{
		while (s[i])
			if (s[i++] == c)
				nb++;
	}
	return (nb);
}
