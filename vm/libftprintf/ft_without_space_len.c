/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without_space_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:35:01 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/02 16:37:51 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_without_space_len(const char *str)
{
	unsigned int space_len;
	unsigned int len;
	unsigned int i;

	space_len = 0;
	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i] && ft_isspace(str[i++]))
			space_len++;
		if (i < len)
		{
			i = len - 1;
			while (str[i] && ft_isspace(str[i--]))
				space_len++;
		}
	}
	return (len - space_len);
}
