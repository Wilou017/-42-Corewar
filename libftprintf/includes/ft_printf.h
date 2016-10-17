/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:15:52 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 16:00:57 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <get_next_line.h>

typedef struct	s_modifieur
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			majspe;
}				t_modifieur;

typedef struct	s_flag
{
	int			diez;
	int			signeplus;
	int			signemoins;
	int			sizefin;
	char		completchar;
}				t_flag;

typedef struct	s_pf_data
{
	char		*setting;
	t_flag		flag;
	int			i;
	int			size;
	int			space;
	int			precision;
	t_modifieur	modifieur;
	char		specifieur;
	int			adjusting;
	char		*ox;
	char		*invalidspe;
}				t_pf_data;
typedef struct	s_ret
{
	char		*finalstr;
	int			*posbs;
	int			return_val;
}				t_ret;

int				ft_printf(char const *s, ...);
char			*ft_pf_nb_precision(t_pf_data *data, char **a);
char			*ft_pf_b_selector(t_pf_data *data, va_list ap);
char			*ft_pf_r_selector(t_pf_data *data, va_list ap);
char			*ft_pf_c_selector(t_pf_data *data, va_list ap, t_ret *retval);
char			*ft_pf_s_selector(t_pf_data *data, va_list ap);
char			*ft_pf_d_selector(t_pf_data *data, va_list ap);
char			*ft_pf_e_selector(t_pf_data *data, va_list ap);
char			*ft_pf_k_selector(va_list ap);
char			*ft_pf_n_selector(va_list ap, t_ret *retval);
char			*ft_pf_p_selector(t_pf_data *data, va_list ap);
char			*ft_pf_t_selector(void);
char			*ft_pf_u_selector(t_pf_data *data, va_list ap);
char			*ft_pf_o_selector(t_pf_data *data, va_list ap);
char			*ft_pf_x_selector(t_pf_data *data, va_list ap);
void			pf_color(char **finalstr);
void			pf_select(t_pf_data *data, va_list ap, t_ret *retval);
int				pf_initdata(t_pf_data *data, va_list ap);
int				pf_check_specifieur(char spe);
char			*ft_pf_str_conscrtuct(t_pf_data *data, char *a);
void			pf_initdata_sizefin(t_pf_data *data);
void			pf_initpreset(t_pf_data *data, va_list ap);

#endif
