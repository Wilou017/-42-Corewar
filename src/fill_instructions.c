/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:35:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/09 22:05:23 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		cw_createnode(header2_t *champion, int *tab, int size)
{
	t_instnode	*new;

	while (/* insctructions */ 0)
	{
		new = (t_instnode*)malloc(sizeof(t_instnode));
		new->inst = /* LALAL */ tab;
		new->size = /* LALAL */ size;
		new->encodage = /* LALAL */ 0;
		cw_pushback_inst(champion, new);
	}
}