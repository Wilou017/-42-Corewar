/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:11:09 by dgalide           #+#    #+#             */
/*   Updated: 2016/03/04 21:53:15 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	int		i;

	if (!s || len <= 0 || !(str = (char *)malloc(sizeof(char) * len + 1)) ||
		start > ft_strlen(s))
		return (NULL);
	j = 0;
	i = start;
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
