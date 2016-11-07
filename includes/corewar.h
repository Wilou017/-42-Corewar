/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:16:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/10/29 18:10:07 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

# include <newlibft.h>
# include <op.h>

typedef struct 		s_instructions
{
	int 			*instructions; // token
	int 			size_instructions; // octet
	int 			encodage;
	struct s_instructions *next;
	struct s_instructions *prev;
}					t_instructions;

typedef struct		header2_s // list champion
{
	unsigned int	id;
	unsigned int	magic;
	char			*prog_name;
	unsigned int	prog_size;
	char			*comment;
	t_instructions  *instructions; // list instruction
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
void			cw_freeall(t_cwdata *data);

#endif