/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spl_block.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:49:30 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/16 15:49:35 by mkopiika         ###   ########.fr       */
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

static int	check_connect(char **blok, int i, int j)
{
	int k;

	k = 0;
	if (j < 3 && (blok[i][j + 1] == '#'))
		k++;
	if (i < 3 && (blok[i + 1][j] == '#'))
		k++;
	if (j >= 1 && (blok[i][j - 1] == '#'))
		k++;
	if (i >= 1 && (blok[i - 1][j] == '#'))
		k++;
	return (k);
}

int			ft_spl_block(char *str)
{
	int		i;
	int		j;
	char	**block;
	int		k;

	k = 0;
	i = 0;
	block = ft_strsplit(str, '\n');
	while (i < 4)
	{
		j = 0;
		while (block[i][j] != '\0')
		{
			if (block[i][j] == '#')
				k += check_connect(block, i, j);
			j++;
		}
		i++;
	}
	free_area(block, 4);
	if (k == 6 || k == 8)
		return (1);
	else
		return (0);
}
