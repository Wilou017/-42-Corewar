/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_cons_pres.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:45:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:05:58 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_nb_precision(t_pf_data *data, char **a)
{
	char	*tmp;

	if (data->precision > 0)
	{
		data->flag.completchar = ' ';
		if ((*a)[0] != '-' && data->precision > (int)ft_strlen((*a)))
			(*a) = ft_strjoin(ft_chartostr('0', data->precision - \
				ft_strlen((*a))), (*a), 3);
		else if ((*a)[0] == '-' && data->precision > (int)ft_strlen((*a)) - 1)
		{
			tmp = (*a);
			(*a) = ft_strjoin(ft_chartostr('0', data->precision - \
				ft_strlen((*a)) + 1), &(*a)[1], 1);
			(*a) = ft_strjoin("-", (*a), 2);
			ft_strdel(&tmp);
		}
		(data->specifieur == 'o') ? (data->flag.diez = 0) : 0;
	}
	else if (data->precision < 0 && ft_strcmp("0", *a) == 0 &&
		(data->flag.completchar = ' '))
	{
		(data->specifieur == 'x') ? (data->flag.diez = 0) : 0;
		ft_strclr(*a);
	}
	return ((*a));
}

char	*ft_pf_str_conscrtuct(t_pf_data *data, char *a)
{
	if (a && data->flag.sizefin > (int)ft_strlen(a))
		a = (data->flag.signemoins) ? (ft_strjoin(a, ft_chartostr(' ',\
			data->flag.sizefin - ft_strlen(a)), 3)) : (ft_strjoin(\
			ft_chartostr(data->flag.completchar, data->flag.sizefin - \
				ft_strlen(a)), a, 3));
	return (a);
}
