/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:07:07 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/30 19:05:02 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define ABS(x) (x < 0) ? -x : x
# define LEN(x) ft_strlen(x)
# define DUP(x) ft_strdup(x)
# define JOIN(x, y, z) ft_strjoin(x, y, z)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef char**					t_tab;
typedef unsigned long long int	t_uintmax;
typedef long long int			t_intmax;

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
char				*ft_chartostr(char c, int nb);
char				*ft_coltostr(char **grille, size_t c);
size_t				ft_countchar(const char *s, char c);
int					ft_delcharinstr(char **alpha, char c, int start);
char				*ft_ftoa(double d, size_t precision);
char				*ft_gather(char **tab, int c);
int					ft_intinarray(int *tab, int nb, int tabsize);
int					ft_intlen(t_intmax nb);
int					ft_intswap(int *a, int *b);
int					*ft_inttabdup(int *tab, int size);
int					ft_inttabmax(int *tab, int size);
int					*ft_inttabjoin(int *tab1, int size1, int *tab2, int size2);
int					ft_inttabmin(int *tab, int size);
int					*ft_inttabnew(size_t size);
int					ft_inttabsorted(int *tab, int size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(t_intmax n, int base);
void				ft_lstadd(t_list **alst, t_list *l_new);
void				ft_lstadd_push_back(t_list **alst, t_list *nw);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstrev(t_list **lst);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_nbchar(const char *s, char c);
int					ft_nbword(const char *s, const char c);
char				*ft_nreplace(char *search, char *rby, char *str, int n);
char				*ft_nwstrtostr(wchar_t *str, size_t j);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putmessage(char *text);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putnstr(char const *s, int n);
int					ft_putnstr_fd(char const *s, int fd, int n);
int					ft_putstr(char const *s);
int					ft_putstr_fd(char const *s, int fd);
int					ft_putwchar(wchar_t chr);
int					ft_putwchar_fd(wchar_t chr, int fd);
t_intmax			ft_pwe(int nb, int pwe);
char				*ft_replace(char *search, char *rby, char *str, int ifre);
void				ft_show_tab(t_tab tab, int mark, char c, int center);
void				ft_showtabint(int *a, int nb_nb, char *tabname, int rev);
int					ft_sqrt(int nb);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strisdigit(char const *s1);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2, int ifre);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strndup(const char *s, int n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnrev(char *c, const int len);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *c);
t_tab				ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strsub(char const *s, unsigned int start, size_t len,\
					size_t fre);
void				ft_strtoupper(char **str);
char				*ft_strtrim(char const *s);
t_tab				ft_tabcpy(t_tab tab);
size_t				ft_tablen(char **tab, int full);
t_tab				ft_tabmalloc(size_t cote, char i);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_wchrtostr(wchar_t chr);
int					ft_without_space_len(const char *str);
char				*ft_wstrtostr(wchar_t *str);

#endif
