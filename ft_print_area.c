/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_area.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:26:46 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 15:26:48 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

void		ft_print_area(char **area, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(area[i]);
		i++;
	}
}
