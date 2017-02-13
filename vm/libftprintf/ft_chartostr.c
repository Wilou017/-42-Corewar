/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:34:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/02/12 11:59:18 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostr(char c, int nb)
{
	char *str;

	str = ft_strnew(nb);
	ft_memset(str, c, nb);
	return (str);
}
