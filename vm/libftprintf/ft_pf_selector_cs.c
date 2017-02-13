/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:30 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_c_selector(t_pf_data *data, va_list ap, t_ret *retval)
{
	int n;
	int pos;

	pos = 0;
	if (data->modifieur.l)
		n = va_arg(ap, int);
	else
		n = (char)va_arg(ap, int);
	if (n == 0)
	{
		while (retval->posbs[pos] > -1)
			pos++;
		retval->posbs[pos] = (data->flag.sizefin == 0 ||
			data->flag.signemoins) ? LEN(retval->finalstr) : (LEN(\
				retval->finalstr) + data->flag.sizefin - 1);
		data->adjusting++;
		n = 'a';
	}
	return (ft_pf_str_conscrtuct(data, ft_wchrtostr(n)));
}

char	*ft_pf_s_selector(t_pf_data *data, va_list ap)
{
	char *a;

	if ((data->modifieur.l || data->modifieur.ll) && data->precision >= 0)
		a = ft_nwstrtostr(va_arg(ap, wchar_t*), data->precision);
	else if (data->precision >= 0)
		a = ft_strndup(va_arg(ap, char*), data->precision);
	else
		a = ft_strdup("");
	return (ft_pf_str_conscrtuct(data, a));
}
