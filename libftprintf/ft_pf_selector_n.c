/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:50 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_n_selector(va_list ap, t_ret *retval)
{
	int *n;

	n = va_arg(ap, int*);
	if (n)
		*n = (int)ft_strlen(retval->finalstr);
	return (ft_strnew(0));
}
