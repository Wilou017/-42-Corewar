/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_ox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_x_conscrtuct(t_pf_data *data, char *a)
{
	if (data->flag.diez && ft_strcmp("0", a))
	{
		if (data->flag.completchar == ' ')
			a = ft_strjoin(data->ox, a, 2);
		else
			data->flag.sizefin -= 2;
	}
	if (a && data->flag.sizefin > (int)ft_strlen(a))
		a = (data->flag.signemoins) ? (ft_strjoin(a, ft_chartostr(' ',\
			data->flag.sizefin - ft_strlen(a)), 3)) : (ft_strjoin(\
			ft_chartostr(data->flag.completchar, data->flag.sizefin - \
				ft_strlen(a)), a, 3));
	(data->flag.diez &&
		ft_strcmp("0", a) && data->flag.completchar == '0') ? \
	(a = ft_strjoin(data->ox, a, 2)) : 0;
	return (a);
}

char	*ft_pf_x_selector(t_pf_data *data, va_list ap)
{
	char		*a;
	t_uintmax	nb;

	if (data->modifieur.l && !data->modifieur.hh && !data->modifieur.ll
		&& !data->modifieur.j && !data->modifieur.z)
		nb = va_arg(ap, unsigned long int);
	else if ((data->modifieur.ll || data->modifieur.j || data->modifieur.z))
		nb = va_arg(ap, unsigned long long int);
	if (data->modifieur.hh)
		nb = (unsigned char)va_arg(ap, int);
	else if (!data->modifieur.l && !data->modifieur.ll
		&& !data->modifieur.j && !data->modifieur.z)
		nb = va_arg(ap, unsigned int);
	a = ft_itoa(nb, 16);
	if (data->modifieur.majspe)
		ft_strtoupper(&a);
	return (ft_pf_x_conscrtuct(data, ft_pf_nb_precision(data, &a)));
}

char	*ft_pf_o_selector(t_pf_data *data, va_list ap)
{
	char		*a;

	if (data->modifieur.ll
		|| data->modifieur.j || data->modifieur.z)
		a = ft_itoa(va_arg(ap, t_uintmax), 8);
	else if (data->modifieur.l)
		a = ft_itoa(va_arg(ap, long int), 8);
	else if (data->modifieur.h)
		a = ft_itoa((unsigned short)va_arg(ap, unsigned int), 8);
	else if (data->modifieur.hh)
		a = ft_itoa((unsigned char)va_arg(ap, int), 8);
	else
		a = ft_itoa(va_arg(ap, unsigned int), 8);\
	return (ft_pf_x_conscrtuct(data, ft_pf_nb_precision(data, &a)));
}
