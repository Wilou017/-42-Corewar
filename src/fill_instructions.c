/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xcfghj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:35:50 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/09 21:39:19 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void		cw_createnode(header2_t *champion, int *tab)
{
	t_instnode	*new;

	while (insctructions)
	{
		new = (t_instnode*)malloc(sizeof(t_instnode));
		new->inst = LALALAL;
		new->size = LALALAL;
		new->encodage = LALALAL;
		cw_pushback_inst(champion, new);
	}
}