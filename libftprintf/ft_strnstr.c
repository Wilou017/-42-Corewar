/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:27:30 by amaitre           #+#    #+#             */
/*   Updated: 2016/03/04 18:43:56 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	n2;
	int		lastresult;

	if (*s2 == '\0')
		return ((char*)s1);
	n2 = ft_strlen(s2);
	lastresult = 1;
	while (n2 <= n && *s1 != '\0'
		&& (lastresult = ft_strncmp(s1, s2, n2)))
	{
		n--;
		s1++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)s1);
}
