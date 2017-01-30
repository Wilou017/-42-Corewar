/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/20 20:19:36 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_opt
{
	ERROR,
	DUMP,
	N,
	V,
	VM
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

typedef struct 			s_param
{
	int					param1;
	int					param2;
	int					param3;
}						t_param;

typedef struct			s_process
{
	int					name;
	int					id;
	int					id_champ;
	int					if_live;
	int					nb_live;
	int					pc;
	int					loca;
	int					encod;
	int					size;
	int					carry;
	int					*reg;
	int					move;
	int					wait_cicle;
	int					good_cicle;
	int					dont_move;
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
	int					init;
	int					last_champ_live;
	int					*mem;
	int					cur_cycle;
	int					cycle_to_die;
	int					dumpcycles;
	int					lastoption;
	char				*lastdata;
	char				**color;
	int					nb_champion;
	int					show_vm;
	int					verbose;
	int					nb_process;
	int					nb_process_total;
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
