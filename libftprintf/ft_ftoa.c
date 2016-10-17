/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:44:02 by amaitre           #+#    #+#             */
/*   Updated: 2016/04/06 22:42:32 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ftoa_cdt(char **bb, char **b, t_intmax *entier, size_t prec)
{
	char *b_cdt;
	char *bb_cdt;

	b_cdt = *b;
	bb_cdt = *bb;
	bb_cdt = ft_strsub(b_cdt, 0, prec, 0);
	if (b_cdt[prec] >= '5')
		bb_cdt[prec - 1] += 1;
	while (prec > 0 && bb_cdt[prec - 1] == ':')
	{
		bb_cdt[prec - 2] += 1;
		bb_cdt[prec - 1] = '0';
		prec--;
	}
	if (!prec)
		*entier += 1;
	*bb = bb_cdt;
	*b = b_cdt;
	return (prec);
}

char		*ft_ftoa_init(t_intmax *entier, double *f)
{
	t_intmax entier2;

	(*entier) = (t_intmax)(*f);
	entier2 = *entier;
	(*f) = (*f) - (*entier);
	if ((*entier) < 0)
	{
		(*entier) = -(*entier);
		(*f) = -(*f);
	}
	return (ft_strdup((entier2 < 0) ? "-" : ""));
}

char		*ft_ftoa(double f, size_t precision)
{
	char		*a;
	char		*b;
	char		*bb;
	t_intmax	entier;

	if (f == 0)
		return (ft_strjoin("0.", ft_chartostr('0', precision), 2));
	a = ft_ftoa_init(&entier, &f);
	while (f - (t_intmax)f > 0)
		f *= 10;
	b = ft_itoa((t_intmax)f, 10);
	if ((bb = b) && ft_strlen(b) > precision)
		precision = ft_ftoa_cdt(&bb, &b, &entier, precision);
	else
		bb = ft_strjoin(bb, ft_chartostr('0', precision - ft_strlen(bb)), 3);
	a = ft_strjoin(ft_strjoin(a, ft_itoa(entier, 10), 3), ".", 1);
	a = ft_strjoin(a, bb, 3);
	return (a);
}
