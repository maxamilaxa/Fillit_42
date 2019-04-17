/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_area.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:08:55 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 15:08:57 by mkopiika         ###   ########.fr       */
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

static char	**malloc_area(int s)
{
	int		i;
	int		j;
	char	**ar;

	i = 0;
	if (!(ar = (char **)malloc(sizeof(char *) * (s + 1))))
		ft_error(23);
	while (i < s)
	{
		if (!(ar[i] = (char *)malloc(sizeof(char) * (s + 1))))
			ft_error(23);
		j = -1;
		while (++j < s)
			ar[i][j] = '.';
		ar[i][j] = '\0';
		i++;
	}
	ar[i] = NULL;
	return (ar);
}

static int	ft_sqrt(int nb)
{
	int		res;

	res = 1;
	while ((res * res) < nb)
		res++;
	return (res);
}

void		ft_make_area(t_etra *lk, int tet)
{
	char	**area;
	int		size;

	if (lk)
	{
		size = ft_sqrt(tet * 4);
		area = malloc_area(size);
		while ((ft_fill_area(lk, area, size)) == 0)
		{
			free_area(area, size);
			size += 1;
			area = malloc_area(size);
		}
		ft_print_area(area, size);
		free_area(area, size);
	}
}
