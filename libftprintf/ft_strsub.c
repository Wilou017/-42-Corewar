/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:26:36 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/05 21:34:59 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len, size_t fre)
{
	char	*result;

	if (len <= 0)
		return (ft_strnew(0));
	result = ft_strnew(len);
	if (s && result && ft_strlen(s) >= len)
		ft_strncpy(result, s + start, len);
	(fre == 1) ? free((char *)s) : 0;
	return (result);
}
