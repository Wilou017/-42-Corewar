/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:19:10 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/01 05:11:54 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2) == 0);
	else
		return (0);
}
