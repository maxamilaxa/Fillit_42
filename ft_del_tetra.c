/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tetra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:46:32 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 14:46:34 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_del_tetra(t_pnt p, char **area)
{
	int x;
	int y;

	x = p.x;
	y = p.y;
	if ((x >= 0 && y >= 0) && (x < p.asize && y < p.asize))
	{
		if (area[y][x] == p.ltr)
		{
			area[y][x] = '.';
			p.y = y - 1;
			ft_del_tetra(p, area);
			p.y = y + 1;
			ft_del_tetra(p, area);
			p.y = y;
			p.x = x - 1;
			ft_del_tetra(p, area);
			p.x = x + 1;
			ft_del_tetra(p, area);
		}
	}
}
