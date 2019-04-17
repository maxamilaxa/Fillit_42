/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:29:03 by mkopiika          #+#    #+#             */
/*   Updated: 2019/03/15 17:29:18 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		valid_last_block(char *s)
{
	t_valid		vd;

	vd.ptr = s;
	vd.i = 0;
	vd.e = 0;
	vd.t = 0;
	vd.r = 0;
	if (!s)
		ft_error(23);
	if (vd.ptr[4] != '\n' || vd.ptr[9] != '\n' || vd.ptr[14] != '\n' ||
			vd.ptr[19] != '\n' || vd.ptr[20] != '\0')
		ft_error(20);
	while (vd.ptr[vd.i] != '\0')
	{
		if (vd.ptr[vd.i] == '.')
			vd.t++;
		if (vd.ptr[vd.i] == '#')
			vd.r++;
		if (vd.ptr[vd.i] == '\n')
			vd.e++;
		vd.i++;
	}
	if (vd.t != 12 || vd.r != 4 || vd.e != 4 || vd.i != 20)
		ft_error(20);
}

static void		valid_block(char *s)
{
	t_valid		vd;

	vd.ptr = s;
	vd.i = 0;
	vd.e = 0;
	vd.t = 0;
	vd.r = 0;
	if (!s)
		ft_error(23);
	if (vd.ptr[4] != '\n' || vd.ptr[9] != '\n' || vd.ptr[14] != '\n' ||
			vd.ptr[19] != '\n' || vd.ptr[20] != '\n')
		ft_error(20);
	while (vd.ptr[vd.i] != '\0')
	{
		if (vd.ptr[vd.i] == '.')
			vd.t++;
		if (vd.ptr[vd.i] == '#')
			vd.r++;
		if (vd.ptr[vd.i] == '\n')
			vd.e++;
		vd.i++;
	}
	if (vd.t != 12 || vd.r != 4 || vd.e != 5 || vd.i != 21)
		ft_error(20);
}

void			ft_valid(char *s, int rd)
{
	if (rd == 21)
		valid_block(s);
	else
		valid_last_block(s);
}
