/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:33:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/17 17:41:57 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
** src/init.c
*/

void		cw_init(t_cwdata *data);
void		cw_lastoption(t_cwdata *data, int i);

/*
** src/get_function.c
*/

int			cw_get_option(t_cwdata *data, int *i);
int			cw_get_champion(t_cwdata *data, int i);

/*
** src/lst_function.c
*/

t_header2	*cw_add_champ_to_lst(t_cwdata *data);
void		cw_freeall(t_cwdata *data);
void		cw_pushback_inst(t_header2 *champion, t_instnode *new);

/*
** src/fill_instruction.c
*/

void		cw_createnode(t_header2 *champion, int *tab, int size);

/*
** src/distrib_function.c
*/

int			cw_distrib_name(t_reedstruct *reed, t_header2 *champion);
int			cw_distrib_comment(t_reedstruct *reed, t_header2 *champion);
int			cw_distrib_program(t_reedstruct *reed, t_header2 *champion);
int			cw_distrib_progsize(t_reedstruct *reed);
int			cw_distrib_padding(t_reedstruct *reed, int ret);

/*
** src/pouette.c
*/

int			cw_pouette(t_reedstruct reed, t_header2 *champion);

#endif
