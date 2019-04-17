/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:25:52 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 15:25:54 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	wr_tetra(t_etra *lk, char **area)
{
	int		i;
	int		j;

	i = lk->y[0];
	j = lk->x[0];
	area[i][j] = lk->ltr;
	area[i + lk->y[1]][j + lk->x[1]] = lk->ltr;
	area[i + lk->y[2]][j + lk->x[2]] = lk->ltr;
	area[i + lk->y[3]][j + lk->x[3]] = lk->ltr;
}

static int	check_size(t_etra *lk, char **area, t_pnt p)
{
	int		done;
	int		k;
	int		x;
	int		y;

	k = 1;
	done = 0;
	while (k < 4)
	{
		x = p.x + lk->x[k];
		y = p.y + lk->y[k];
		if ((y >= 0) && (y < p.asize) && (x >= 0) && (x < p.asize))
		{
			if (area[y][x] == '.')
				done++;
		}
		k++;
	}
	if (done == 3)
		return (1);
	else
		return (0);
}

static int	free_place(t_etra *lk, char **area, int size)
{
	t_pnt	p;

	p.asize = size;
	p.y = (lk->y[0] == -2) ? 0 : lk->y[0];
	while (p.y < size)
	{
		p.x = (lk->x[0] != -2 && p.y == lk->y[0]) ? lk->x[0] : 0;
		while (p.x < size)
		{
			if (area[p.y][p.x] == '.')
			{
				if (check_size(lk, area, p) == 1)
				{
					lk->y[0] = p.y;
					lk->x[0] = p.x;
					return (1);
				}
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

static void	move_tetra(t_etra *lk, char **area, int size)
{
	t_pnt	p;

	lk->x[0] = -2;
	lk->y[0] = -2;
	lk = lk->prv;
	p.x = lk->x[0];
	p.y = lk->y[0];
	p.asize = size;
	p.ltr = lk->ltr;
	ft_del_tetra(p, area);
	if (lk->x[0] + 1 < size)
		lk->x[0]++;
	else if (lk->y[0] + 1 < size)
	{
		lk->x[0] = 0;
		lk->y[0]++;
	}
}

int			ft_fill_area(t_etra *lk, char **area, int size)
{
	int		place;

	while (lk)
	{
		place = free_place(lk, area, size);
		if (place == 1)
		{
			wr_tetra(lk, area);
			lk = lk->nxt;
		}
		else if (place == 0 && lk->prv)
		{
			move_tetra(lk, area, size);
			lk = lk->prv;
		}
		else if (place == 0 && lk->prv == NULL)
		{
			lk->x[0] = -2;
			lk->y[0] = -2;
			return (0);
		}
	}
	return (1);
}
