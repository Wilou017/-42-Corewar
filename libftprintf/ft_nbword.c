/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:09:09 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/02 19:30:07 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbword(const char *s, const char c)
{
	unsigned int count;
	unsigned int i;

	count = 0;
	if (s && c)
	{
		if (s[0] && s[0] != c)
			count = 1;
		else
			count = 0;
		i = 1;
		while (s[0] && s[i])
		{
			if (s[i - 1] == c && s[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}
