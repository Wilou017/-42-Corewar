/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:55:26 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:07:05 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_u_conscrtuct(t_pf_data *data, char *a)
{
	if (data->flag.sizefin > (int)ft_strlen(a) && !data->flag.signemoins)
		a = ft_strjoin(ft_chartostr(data->flag.completchar, data->flag.sizefin\
			- ft_strlen(a)), a, 3);
	else if (data->flag.sizefin > (int)ft_strlen(a) && data->flag.signemoins)
		a = ft_strjoin(a, ft_chartostr(' ', data->flag.sizefin\
			- ft_strlen(a)), 3);
	return (a);
}

char	*ft_pf_u_selector(t_pf_data *data, va_list ap)
{
	t_uintmax	n;
	t_uintmax	gh;
	char		*a;

	if (data->modifieur.l || data->modifieur.ll
		|| data->modifieur.j || data->modifieur.z)
	{
		n = va_arg(ap, t_uintmax);
		gh = 1000000000;
		gh *= 10000000000;
		a = (n > gh) ? ft_strjoin(ft_strdup("1"), ft_itoa(n - gh, 10), 3) :\
		ft_itoa(n, 10);
	}
	else if (data->modifieur.h && !data->modifieur.z)
		a = ft_itoa((unsigned short)va_arg(ap, unsigned int), 10);
	else if (data->modifieur.hh && !data->modifieur.z)
		a = ft_itoa((unsigned char)va_arg(ap, int), 10);
	else
		a = ft_itoa(va_arg(ap, unsigned int), 10);
	return (ft_pf_u_conscrtuct(data, ft_pf_nb_precision(data, &a)));
}
