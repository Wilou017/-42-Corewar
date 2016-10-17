/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:35 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_pf_d_conscrtuct_nbplus(t_pf_data *data, char **a)
{
	if (data->flag.signeplus && data->flag.completchar == ' ')
		*a = ft_strjoin("+", *a, 2);
	if (data->flag.signeplus && data->flag.completchar != ' ')
		data->flag.sizefin--;
	if (data->flag.sizefin > (int)LEN(*a))
		*a = ft_strjoin(ft_chartostr(data->flag.completchar, data->flag.sizefin\
			- LEN(*a)), *a, 3);
	if (data->flag.signeplus && data->flag.completchar != ' ')
		*a = ft_strjoin("+", *a, 2);
	(data->space) ? (*a = ft_strjoin(" ", *a, 2)) : 0;
}

void	ft_pf_d_conscrtuct_nbmoins(t_pf_data *data, char **a)
{
	if (data->flag.completchar != ' ')
	{
		ft_delcharinstr(a, '-', 1);
		data->flag.sizefin--;
	}
	if (data->flag.sizefin > (int)LEN(*a))
		*a = ft_strjoin(ft_chartostr(data->flag.completchar, data->flag.sizefin\
			- LEN(*a)), *a, 3);
	(data->flag.completchar != ' ') ? (*a = ft_strjoin("-", *a, 2)) : 0;
}

void	ft_pf_d_conscrtuct_moins(t_pf_data *data, char **a)
{
	if (data->flag.signeplus && *a[0] != '-')
		*a = ft_strjoin("+", *a, 2);
	if (data->flag.sizefin > (int)LEN(*a))
		*a = ft_strjoin(*a, ft_chartostr(' ', data->flag.sizefin\
			- LEN(*a)), 3);
	(*a[0] != '-' && data->space) ? (*a = ft_strjoin(" ", *a, 2)) : 0;
}

char	*ft_pf_d_conscrtuct(t_pf_data *data, char *a)
{
	(data->space) ? (data->flag.sizefin -= 1) : 0;
	if (!data->flag.signemoins)
		if (a[0] != '-')
			ft_pf_d_conscrtuct_nbplus(data, &a);
		else
			ft_pf_d_conscrtuct_nbmoins(data, &a);
	else
		ft_pf_d_conscrtuct_moins(data, &a);
	return (a);
}

char	*ft_pf_d_selector(t_pf_data *data, va_list ap)
{
	char	*a;

	if (data->modifieur.z)
		a = ft_itoa(va_arg(ap, size_t), 10);
	else if (data->modifieur.ll || data->modifieur.j)
		a = ft_itoa(va_arg(ap, long long int), 10);
	else if (data->modifieur.l)
		a = ft_itoa(va_arg(ap, long int), 10);
	else if (data->modifieur.h)
		a = ft_itoa((short)va_arg(ap, int), 10);
	else if (data->modifieur.hh)
		a = ft_itoa((char)va_arg(ap, int), 10);
	else
		a = ft_itoa(va_arg(ap, int), 10);
	return (ft_pf_d_conscrtuct(data, ft_pf_nb_precision(data, &a)));
}
