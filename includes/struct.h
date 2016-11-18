/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/17 17:38:24 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_instnode
{
	int					*inst;
	int					size;
	int					encodage;
	struct s_instnode	*next;
	struct s_instnode	*prev;
}						t_instnode;

typedef struct			s_instdata
{
	int					size;
	t_instnode			*start;
	t_instnode			*end;
}						t_instdata;

typedef struct			s_process
{
	int					pc;
	int					carry;
	int					*reg;
}						t_process;

typedef struct			s_header2
{
	unsigned int		id;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*comment;
	int					*prog;
	t_instdata			inst;
	t_process			process;
}						t_header2;

typedef	struct			s_cwdata
{
	int					*mem;
	int					dumpcycles;
	int					lastoption;
	char				*lastdata;
	int					nb_champion;
	int					begin_champ2;
	int					begin_champ3;
	int					begin_champ4;
	t_tab				v;
	int					c;
	t_list				*beginlist;
}						t_cwdata;

typedef	struct			s_reedstruct
{
	int					fd;
	int					ret;
	int					buf;
	int					status;
	int					reedsize;
	int					inst_index;
	int					inst_size;
	int					*inst_tab;
}						t_reedstruct;

typedef enum			e_opt
{
	ERROR,
	DUMP,
	N
}						t_opt;

#endif
