/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_k.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:10:08 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:06:42 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		pf_k_selectmois(const char *str)
{
	if (!ft_strcmp(str, "janvier"))
		return (1);
	else if (!ft_strcmp(str, "fevrier") || !ft_strcmp(str, "février"))
		return (2);
	else if (!ft_strcmp(str, "mars"))
		return (3);
	else if (!ft_strcmp(str, "avril"))
		return (4);
	else if (!ft_strcmp(str, "mai"))
		return (5);
	else if (!ft_strcmp(str, "juin"))
		return (6);
	else if (!ft_strcmp(str, "juillet"))
		return (7);
	else if (!ft_strcmp(str, "aout"))
		return (8);
	else if (!ft_strcmp(str, "septembre"))
		return (9);
	else if (!ft_strcmp(str, "octobre"))
		return (10);
	else if (!ft_strcmp(str, "novembre"))
		return (11);
	else if (!ft_strcmp(str, "decembre") || !ft_strcmp(str, "décembre"))
		return (12);
	return (-1);
}

char	*ft_pf_k_selector_slash(char *a_chartime)
{
	char	**chartime;
	int		jour;
	int		mois;

	chartime = ft_strsplit(a_chartime, '/');
	jour = ft_atoi(chartime[0]);
	mois = ft_atoi(chartime[1]);
	if (jour < 1 || jour > 31 ||
		(mois == 2 && jour > 29) ||
		mois < 1 || mois > 12)
		return (DUP("Error Date"));
	return (JOIN(JOIN(JOIN(JOIN(chartime[2], "-", 1), (LEN(chartime[1]) < 2) ?\
	JOIN("0", chartime[1], 2) : chartime[1], 3), "-", 1), (LEN(\
	chartime[0]) < 2) ? JOIN("0", chartime[0], 2) : chartime[0], 3));
}

char	*ft_pf_k_selector_space(char *a_chartime)
{
	char	**chartime;
	int		mois;
	int		jour;

	chartime = ft_strsplit(a_chartime, ' ');
	mois = pf_k_selectmois(chartime[1]);
	jour = ft_atoi(chartime[0]);
	if (jour < 1 || jour > 31 ||
		(mois == 2 && jour > 29) ||
		LEN(chartime[2]) != 4 ||
		mois == -1)
		return (DUP("Error Date"));
	return (JOIN(JOIN(JOIN(JOIN(chartime[2], "-", 1), (mois < 10) ? JOIN("0", \
		ft_itoa(mois, 10), 2) : ft_itoa(mois, 10), 3), "-", 1), (LEN(\
	chartime[0]) < 2) ? JOIN("0", chartime[0], 2) : chartime[0], 3));
}

char	*ft_pf_k_selector(va_list ap)
{
	char	*a_chartime;

	a_chartime = va_arg(ap, char*);
	if (ft_countchar(a_chartime, ' ') == 2)
		return (ft_pf_k_selector_space(a_chartime));
	if (ft_countchar(a_chartime, '/') == 2)
		return (ft_pf_k_selector_slash(a_chartime));
	else
		return (DUP("Error Date"));
}
