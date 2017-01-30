/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:34:08 by amaitre           #+#    #+#             */
/*   Updated: 2017/01/18 20:57:55 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define DEBUG_PARSINGCOR		0

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define NB_OCT_LINE			64
# define CHAMP_COLOR			"Color: red blue green yellow"

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define WAIT_LIVE				10
# define WAIT_LD				5
# define WAIT_ST				5
# define WAIT_ADD				10
# define WAIT_SUB				10
# define WAIT_AND				6
# define WAIT_OR				6
# define WAIT_XOR				6
# define WAIT_ZJUMP				20
# define WAIT_LDI				25
# define WAIT_STI				25
# define WAIT_FORK				800
# define WAIT_LLD				10
# define WAIT_LLDI				50
# define WAIT_LFORK				1000
# define WAIT_AFF				2

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define COLONE_TEXT			NB_OCT_LINE * 3 + 7

#endif
