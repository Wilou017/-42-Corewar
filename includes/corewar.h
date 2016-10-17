/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:16:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/28 20:55:48 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

# include <newlibft.h>
# include <op.h>

typedef	struct	s_cwdata
{
	int			dumpcycles;
	int			lastoption;
	int			nb_champion;
	t_tab		v;
	int			c;
}				t_cwdata;

typedef enum		e_opt
{
	ERROR,
	DUMP,
	N
}					t_opt;

void			cw_init(t_cwdata *data);
int				get_option(t_cwdata *data, int *i);
int				get_champion(t_cwdata *data, int i);
void 			lastoption(t_cwdata *data, int i);

#endif