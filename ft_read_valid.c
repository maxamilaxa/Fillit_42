/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:13:49 by mkopiika          #+#    #+#             */
/*   Updated: 2019/03/16 13:13:52 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	make_valid(char *b, int rd)
{
	b[rd] = '\0';
	ft_valid(b, rd);
	if (ft_spl_block(b) == 0)
		ft_error(20);
}

int			ft_read_valid(int fd)
{
	char	b[22];
	int		rd;
	int		tet;

	tet = 0;
	while ((rd = read(fd, b, 21)) == 21)
	{
		tet++;
		make_valid(b, rd);
	}
	if (rd == 20 && tet < 26)
	{
		tet++;
		make_valid(b, rd);
	}
	else
		ft_error(20);
	return (tet);
}
