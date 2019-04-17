/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:26:26 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 15:26:27 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_area(char **area, int size)
{
	int		i;

	i = 0;
	if (area)
	{
		while (i < size)
		{
			free(area[i]);
			i++;
		}
		free(area);
	}
}

static void		read_fig(char **tmp, t_etra *link)
{
	t_iter		itr;

	itr.i = -1;
	itr.f = 0;
	while (++itr.i < 4)
	{
		itr.j = -1;
		while (tmp[itr.i][++itr.j] != '\0')
		{
			if (tmp[itr.i][itr.j] == '#')
			{
				if (itr.f == 0)
				{
					itr.cy = itr.i;
					itr.cx = itr.j;
				}
				else
				{
					link->x[itr.f] = itr.j - itr.cx;
					link->y[itr.f] = itr.i - itr.cy;
				}
				itr.f++;
			}
		}
	}
}

static t_etra	*malloc_link(t_etra *link)
{
	if (!link)
	{
		if (!(link = (t_etra *)malloc(sizeof(t_etra))))
			ft_error(23);
		link->ltr = 'A';
		link->x[0] = -2;
		link->y[0] = -2;
		link->nxt = NULL;
		link->prv = NULL;
		return (link);
	}
	else
	{
		if (!(link->nxt = (t_etra *)malloc(sizeof(t_etra))))
			ft_error(23);
		link->nxt->ltr = link->ltr + 1;
		link->nxt->x[0] = -2;
		link->nxt->y[0] = -2;
		link->nxt->nxt = NULL;
		link->nxt->prv = link;
		return (link->nxt);
	}
}

t_etra			*ft_make_link(int fd)
{
	char		**tmp;
	int			rd;
	char		b[22];
	t_etra		*lk;

	lk = NULL;
	while ((rd = read(fd, b, 21)) > 0)
	{
		b[rd] = '\0';
		lk = malloc_link(lk);
		tmp = ft_strsplit(b, '\n');
		read_fig(tmp, lk);
		free_area(tmp, 4);
	}
	while (lk->prv)
		lk = lk->prv;
	return (lk);
}
