/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:13:12 by mkopiika          #+#    #+#             */
/*   Updated: 2019/03/15 17:13:15 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_putendl(char const *s)
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

void			ft_error(int f)
{
	if (f == 20)
	{
		ft_putendl("error");
		exit(20);
	}
	else if (f == 21)
	{
		ft_putendl("usage: ./fillit source_file.fillit");
		exit(21);
	}
	else if (f == 22)
	{
		ft_putendl("error");
		exit(22);
	}
	else if (f == 23)
		exit(23);
	else
		exit(29);
}
