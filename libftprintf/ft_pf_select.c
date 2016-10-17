/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 19:31:21 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:20 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	pf_concfinal(t_ret *retval, char **a, t_pf_data *data)
{
	if (*a == NULL)
		ft_strcpy((*a = ft_strnew(6)), "(null)");
	retval->finalstr = ft_strjoin(retval->finalstr, (*a), 3);
	ft_strdel(&data->ox);
}

static void	pf_select2(t_pf_data *data, va_list ap, t_ret *retval, char **a)
{
	if (data->specifieur == 'd' || (data->specifieur == 'i' &&
		!data->modifieur.majspe))
		(*a) = ft_pf_d_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'u')
		(*a) = ft_pf_u_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == '%')
		(*a) = ft_pf_str_conscrtuct(data, ft_chartostr('%', 1));
	else if ((*a) == NULL && data->specifieur == 's')
		(*a) = ft_pf_s_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'o')
		(*a) = ft_pf_o_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'c')
		(*a) = ft_pf_c_selector(data, ap, retval);
	else if ((*a) == NULL && data->specifieur == 'x')
		(*a) = ft_pf_x_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'p' && !data->modifieur.majspe)
		(*a) = ft_pf_p_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'b')
		(*a) = ft_pf_b_selector(data, ap);
	else if ((*a) == NULL && data->specifieur == 'f')
		(*a) = ft_ftoa(va_arg(ap, double), (data->precision == 0) ? 6 : \
			data->precision);
	else if ((*a) == NULL && data->invalidspe != NULL)
		(*a) = ft_pf_str_conscrtuct(data, data->invalidspe);
	pf_concfinal(retval, a, data);
}

void		pf_select(t_pf_data *data, va_list ap, t_ret *retval)
{
	char	*a;

	a = ((data->specifieur == 'j' || data->specifieur == 'z' ||
		data->specifieur == 'l' || data->specifieur == 'h'
		|| data->specifieur == ' ') &&
		!data->modifieur.majspe) ? ft_strnew(0) : NULL;
	if (data->specifieur == 'n' && !data->modifieur.majspe)
		a = ft_pf_n_selector(ap, retval);
	else if (data->specifieur == 'k')
		a = ft_pf_k_selector(ap);
	else if (data->specifieur == 'e')
		a = ft_pf_e_selector(data, ap);
	else if (data->specifieur == 'r' && !data->modifieur.majspe)
		a = ft_pf_r_selector(data, ap);
	else if (data->specifieur == 't')
		a = ft_pf_t_selector();
	pf_select2(data, ap, retval, &a);
	data->i += data->size;
}
