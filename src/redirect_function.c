/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:57:33 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/26 17:13:49 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void		redirect_function(t_cwdata *data, t_func func, t_process *proc)
{
	if (func == LIVE)
		cw_fc_live(data, proc);
	else if (func == LD)
		cw_fc_ld(data, proc);
}