/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:55:55 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 18:59:55 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAPS_H
# define FT_TERMCAPS_H

# include <ft_printf.h>

void			ft_termcaps_downline(int nbline);
void			ft_termcaps_leftcurs(int nbcol);
void			ft_termcaps_lineclear(void);
void			ft_termcaps_poscurs(int line, int col);
void			ft_termcaps_restorecurs(void);
void			ft_termcaps_rightcurs(int nbcol);
void			ft_termcaps_savecurs(void);
void			ft_termcaps_screenclear(void);
void			ft_termcaps_upline(int nbline);

#endif
