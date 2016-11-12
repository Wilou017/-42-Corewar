/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 16:16:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/11/12 18:36:26 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <newlibft.h>

# define DEBUG_PARSINGCOR		1

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

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8


# define PROG_NAME_LENGTH		(128) // TAILLE DU NOM
# define COMMENT_LENGTH			(2048) // TAILLE DU COMMENTAIRE
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			s_instnode
{
	int					*inst;		// token
	int					size;		// octet
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

typedef struct			s_header2	// list champion
{
	unsigned int		id;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*comment;
	t_instdata			inst;		// list instruction
}						t_header2;

typedef	struct			s_cwdata
{
	int					dumpcycles;
	int					lastoption;
	char				*lastdata;
	int					nb_champion;
	t_tab				v;
	int					c;
	t_list				*beginlist;
}						t_cwdata;

typedef	struct			s_reedstruct
{
	int			fd;
	int			ret;
	int			buf;
	int			status;
	int			reedsize;
	int			inst_index;
	int			inst_size;
	int			*inst_tab;
}						t_reedstruct;

typedef enum			e_opt
{
	ERROR,
	DUMP,
	N
}						t_opt;

void					cw_init(t_cwdata *data);
int						cw_get_option(t_cwdata *data, int *i);
int						cw_get_champion(t_cwdata *data, int i);
t_header2				*cw_add_champ_to_lst(t_cwdata *data);
void					cw_lastoption(t_cwdata *data, int i);
void					cw_freeall(t_cwdata *data);
void					cw_pushback_inst(t_header2 *champion, t_instnode *new);
void					cw_createnode(t_header2 *champion, int *tab, int size);

#endif
