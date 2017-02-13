/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:21:11 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 16:00:58 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libft.h>
# define BUFF_SIZE 4096

typedef struct	s_fd
{
	int			fd;
	char		*res;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif
