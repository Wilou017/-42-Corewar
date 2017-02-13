/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:31:30 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/02 16:37:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		len = ft_without_space_len(s);
		if (len > 0)
		{
			i = 0;
			result = ft_strnew(len);
			if (result)
			{
				while (s[i] && ft_isspace(s[i]))
					i++;
				if (!*(s + i))
					return (ft_strnew(0));
				ft_strncpy(result, &s[i], len);
			}
			return (result);
		}
	}
	return (ft_strnew(0));
}
