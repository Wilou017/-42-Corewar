/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:59:41 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/18 20:02:49 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cw_distrib_name(t_reedstruct *reed, t_header *champion)
{
	// if (DEBUG_PARSINGCOR && reed->buf)
	// 	ft_printf("%04d Nom ? -> {lred}%.2X{eoc} -> %c\n", reed->status,
	// 		reed->buf, reed->buf);
	champion->prog_name = ft_strjoin(champion->prog_name,
		ft_chartostr(reed->buf, 1), 3);
	if (reed->status == PROG_NAME_LENGTH + (int)sizeof(champion->magic) - 1)
		return (sizeof(int));
	return (1);
}

int		cw_distrib_comment(t_reedstruct *reed, t_header *champion)
{
	// if (DEBUG_PARSINGCOR && reed->buf)
	// 	ft_printf("%04d Comment ? -> {lred}%.2X{eoc} -> %c\n", reed->status,
	// 		reed->buf, reed->buf);
	champion->comment = ft_strjoin(champion->comment,
		ft_chartostr(reed->buf, 1), 3);
	if (reed->status == PROG_NAME_LENGTH + (int)sizeof(champion->magic)
	+ 2 * sizeof(int) + COMMENT_LENGTH - 1)
		return (sizeof(int));
	return (1);
}

int		cw_distrib_program(t_reedstruct *reed, t_header *champion)
{
	if (reed->status == PROG_NAME_LENGTH + (int)sizeof(champion->magic)
	+ 3 * sizeof(int) + COMMENT_LENGTH && reed->buf == 0)
		return (-4);
	reed->inst_tab[reed->inst_index] = reed->buf;
	reed->inst_index++;
// 	if (DEBUG_PARSINGCOR)
// 		ft_printf("%04d Programme -> {lred}%.2X{eoc} -> {lblue}%.2b{eoc} \
// -> {lgreen}%03d{eoc}\n", reed->status, reed->buf, reed->buf, reed->buf);
	return (1);
}

int		cw_distrib_progsize(t_reedstruct *reed)
{
	if (reed->buf == 0)
		return (-2);
// 	if (DEBUG_PARSINGCOR)
// 		ft_printf("%04d Progsize ? -> {lred}%.8X{eoc} -> \
// {lgreen}%d{eoc}\n", reed->status, reed->buf, reed->buf);
	reed->inst_tab = ft_inttabnew(reed->buf, -1);
	reed->inst_size = reed->buf;
	reed->inst_index = 0;
	reed->status += 3;
	return (1);
}

int		cw_distrib_padding(t_reedstruct *reed, int ret)
{
	if (reed->buf != 0)
		return (ret);
	// if (DEBUG_PARSINGCOR)
	// 	ft_printf("%04d Padding -> {lred}%.8X{eoc}\n", reed->status, reed->buf);
	reed->status += 3;
	if (ret == -1)
		return(sizeof(int));
	return (1);
}
