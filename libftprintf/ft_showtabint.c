/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showtabint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:29:52 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/19 22:07:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_showtabint(int *a, int nb_nb, char *tabname, int rev)
{
	int i;

	i = -1;
	ft_printf("\n");
	if (nb_nb > 0 && rev)
	{
		i = nb_nb;
		while (--i >= 0)
		{
			ft_printf("  {lyellow}%s{lred}[{lcyan}%03d{lred}]", tabname, i);
			ft_printf("{eoc} = {lgreen}%03d{eoc}\n", a[i]);
		}
	}
	while (!rev && ++i < nb_nb)
	{
		ft_printf("  {lyellow}%s{lred}[{lcyan}%03d{lred}]", tabname, i);
		ft_printf("{eoc} = {lgreen}%03d{eoc}\n", a[i]);
	}
	if (nb_nb == 0)
		ft_printf("  {lyellow}%s {lcyan}➜ {lred} 0 element{eoc}\n", tabname);
	ft_printf("\n");
}
