/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_selector_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 17:55:26 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/10 12:07:02 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_pf_t_selector(void)
{
	char		*a;

	a = DUP("\n                      __---__\n                   _-       _--");
	a = JOIN(a, "______\n              __--( /     \\ )XXXXXXXXXXXXX_\n   ", 1);
	a = JOIN(a, "         --XXX(   O   O  )XXXXXXXXXXXXXXX-\n           /X", 1);
	a = JOIN(a, "( XX      U     )        XXXXXXX\\\n         /XXXXX(     ", 1);
	a = JOIN(a, "         )--_  XXXXXXXXXXX\\\n       /XXXXX/ (       O   ", 1);
	a = JOIN(a, "  )   XXXXXX   \\XXXXX\\\n        XXXXX/   /            X", 1);
	a = JOIN(a, "XXXXX   \\__ \\XXXXX----\n        XXXXXX__/          XXXX", 1);
	a = JOIN(a, "XX         \\__----  -\n---___  XXX__/          XXXXXX   ", 1);
	a = JOIN(a, "   \\__         ---\n  --  --__/   ___/\\  XXXXXX        ", 1);
	a = JOIN(a, "    /  ___---=\n    -_    ___/    XXXXXX              '--", 1);
	a = JOIN(a, "- XXXXXX\n      --\\/XXX\\ XXXXXX                      /X", 1);
	a = JOIN(a, "XXXX\n        \\XXXXXXXXX                        /XXXXX/", 1);
	a = JOIN(a, "\n         \\XXXXXX                        _/XXXXX/\n    ", 1);
	a = JOIN(a, "       \\XXXXX--__/              __-- XXXX/\n            ", 1);
	a = JOIN(a, "--XXXXXXX---------------  XXXXX--\n               \\XXXXX", 1);
	a = JOIN(a, "XXXXXXXXXXXXXXXXXXX-\n                 --XXXXXXXXXXXXXXXX", 1);
	a = JOIN(a, "XX-\n           * * * * * who ya gonna call? * * * * *\n", 1);
	a = JOIN(a, "                 * * * ghostbusters!! * * *\n", 1);
	return (a);
}
