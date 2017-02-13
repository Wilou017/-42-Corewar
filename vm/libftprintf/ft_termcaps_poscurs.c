/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps_poscurs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:57:17 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/11 21:12:58 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_termcaps.h>

void			ft_termcaps_poscurs(int line, int col)
{
	ft_printf("\033[%d;%dH", line, col);
}
