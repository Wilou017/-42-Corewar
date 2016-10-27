/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:16:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/27 18:32:36 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

# include <newlibft.h>
# include <op.h>

typedef struct		header2_s
{
	unsigned int	id;
	unsigned int	magic;
	char			*prog_name;
	unsigned int	prog_size;
	char			*comment;
}					header2_t;

typedef	struct	s_cwdata
{
	int			dumpcycles;
	int			lastoption;
	char		*lastdata;
	int			nb_champion;
	t_tab		v;
	int			c;
	t_list		*beginlist;
}				t_cwdata;


typedef enum		e_opt
{
	ERROR,
	DUMP,
	N
}					t_opt;

void			cw_init(t_cwdata *data);
int				cw_get_option(t_cwdata *data, int *i);
int				cw_get_champion(t_cwdata *data, int i);
header2_t		*cw_add_champ_to_lst(t_cwdata *data);
void 			cw_lastoption(t_cwdata *data, int i);

#endif