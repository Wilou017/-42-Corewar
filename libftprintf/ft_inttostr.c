/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:24:15 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/29 17:27:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_inttostr(int octet)
{
	char *str;

	str = ft_strnew(4);
	str[0] = octet >> 24;
	str[1] = octet >> 16;
	str[2] = octet >> 8;
	str[3] = octet >> 0;
	return (str);
}
