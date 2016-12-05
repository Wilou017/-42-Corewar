/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/12/05 21:31:45 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_opt
{
	ERROR,
	DUMP,
	N
}						t_opt;

typedef enum			e_func
{
	RIEN,
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJUMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}						t_func;

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
	int					id;
	int					id_champ;
	int					if_live;
	int					nb_live;
	int					pc;
	int					loca;
	int					encod;
	int					carry;
	int					*reg;
	int					move;
	int					wait_cicle;
}						t_process;

typedef struct			s_header
{
	unsigned int		id;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*comment;
	int					*prog;
	int					if_live;
	int					nb_live;
	t_instdata			inst;
}						t_header;

typedef struct			s_inst
{
	int					param;
	char				*bin;
	int					label_size;
	int					size;
}						t_inst;

typedef	struct			s_cwdata
{
	int					*mem;
	int					cur_cycle;
	int					cycle_to_die;
	int					dumpcycles;
	int					lastoption;
	char				*lastdata;
	char				**color;
	int					nb_champion;
	int					nb_process;
	int					nb_live_per_cycle;
	int					*begin_champ;
	t_tab				v;
	int					c;
	t_list				*beginlist;
	t_list				*processlist;
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

typedef struct			s_vm_data
{
	int					check;
	int					cur_cycle;
}						t_vm_data;

#endif
