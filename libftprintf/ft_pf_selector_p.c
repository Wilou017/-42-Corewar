/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:58 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_p_selector(t_pf_data *data, va_list ap)
{
	char *a;

	a = ft_itoa(va_arg(ap, t_intmax), 16);
	if (data->precision > (int)ft_strlen(a))
		a = ft_strjoin(ft_chartostr('0', data->precision - ft_strlen(a)), a, 3);
	if (data->precision < 0 && ft_strcmp("0", a) == 0)
		ft_strclr(a);
	a = ft_strjoin(data->ox, a, 2);
	if (data->flag.sizefin > (int)ft_strlen(a))
		a = (!data->flag.signemoins && data->flag.completchar != '0') ? \
			(ft_strjoin(ft_chartostr(' ', data->flag.sizefin - \
			ft_strlen(a)), a, 3)) : (ft_strjoin(a, ft_chartostr(\
			data->flag.completchar, data->flag.sizefin - ft_strlen(a)), 3));
	return (a);
}
