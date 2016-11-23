/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/23 15:24:54 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
** src/init.c
*/

int			cw_init(t_cwdata *data);
void		cw_lastoption(t_cwdata *data, int i);

/*
** src/get_function.c
*/

int			cw_get_option(t_cwdata *data, int *i);
int			cw_get_champion(t_cwdata *data, int i);

/*
** src/lst_function.c
*/

t_header	*cw_add_champ_to_lst(t_cwdata *data);
void		cw_freeall(t_cwdata *data);
void		cw_pushback_inst(t_header *champion, t_instnode *new);
t_process	*cw_add_process_to_lst(t_header *champ);

/*
** src/fill_instruction.c
*/

void		cw_createnode(t_header *champion, int *tab, int size);

/*
** src/distrib_function.c
*/

int			cw_distrib_name(t_reedstruct *reed, t_header *champion);
int			cw_distrib_comment(t_reedstruct *reed, t_header *champion);
int			cw_distrib_program(t_reedstruct *reed, t_header *champion);
int			cw_distrib_progsize(t_reedstruct *reed);
int			cw_distrib_padding(t_reedstruct *reed, int ret);

/*
** src/pouette.c
*/

int			cw_pouette(t_reedstruct reed, t_header *champion);

/*
** src/creat_mem.c
*/

void		print_map(t_cwdata *data);
void		create_map(t_cwdata *data);

/*
** src/vm_loop.c
*/

void		cw_loop(t_cwdata *data);

/*
** src/corewar.c
*/

int			corewar(t_cwdata *data);

/*
** src/encodage.c
*/

int			encod(t_header *champion, t_cwdata *data);
int			if_encodage(int opcode);
int			check_opcode(int opcode);

#endif
