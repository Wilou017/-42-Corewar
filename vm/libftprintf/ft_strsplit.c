/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:29:24 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/25 13:14:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloctab(const char *s, char c, size_t nbword)
{
	char	**tab;
	size_t	ligne;
	size_t	nb;
	size_t	i;

	ligne = 0;
	i = 0;
	nbword = ft_nbword(s, c);
	tab = (char **)malloc(sizeof(char *) * (nbword + 1));
	tab[nbword] = NULL;
	while (ligne < nbword)
	{
		while (s[i] && s[i] == c)
			i++;
		nb = ft_nbchar(&s[i], c);
		tab[ligne] = (char *)malloc(sizeof(char) * (nb + 1));
		tab[ligne++][nb] = '\0';
		i += nb;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	ligne;
	size_t	colone;
	size_t	i;

	if (s)
	{
		tab = ft_malloctab(s, c, ft_nbword(s, c));
		ligne = 0;
		i = 0;
		while (s[i])
		{
			colone = 0;
			while (s[i] && s[i] == c)
				i++;
			while (s[i] && s[i] != c)
				tab[ligne][colone++] = s[i++];
			ligne++;
		}
		return (tab);
	}
	return (NULL);
}
