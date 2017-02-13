/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:34:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/05 22:08:12 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wchrtostr(wchar_t chr)
{
	char *str;

	str = ft_strnew(0);
	if (chr <= 0x7F)
		str = ft_strjoin(str, ft_chartostr(chr, 1), 3);
	else if (chr <= 0x7FF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 6) + 0xC0, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	else if (chr <= 0xFFFF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 12) + 0xE0, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 6) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	else if (chr <= 0x10FFFF)
	{
		str = ft_strjoin(str, ft_chartostr((chr >> 18) + 0xF0, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 12) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr(((chr >> 6) & 0x3F) + 0x80, 1), 3);
		str = ft_strjoin(str, ft_chartostr((chr & 0x3F) + 0x80, 1), 3);
	}
	return (str);
}
