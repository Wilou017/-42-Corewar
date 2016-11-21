/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pouette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:17:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/19 16:05:42 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <corewar.h>

int		cw_pouette(t_reedstruct reed, t_header *champion)
{
	//ft_printf("\n\nNom     = %s\n", champion->prog_name);
	//ft_printf("Comment = %s\n", champion->comment);

	cw_createnode(champion, reed.inst_tab, reed.inst_size);
	champion->prog = reed.inst_tab;
	champion->prog_size = reed.inst_size;
	return (0);
}