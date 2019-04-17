/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:53:01 by mkopiika          #+#    #+#             */
/*   Updated: 2019/03/14 14:53:03 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		tet;
	t_etra	*lk;

	if (argc != 2)
		ft_error(21);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(22);
	tet = ft_read_valid(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(22);
	lk = ft_make_link(fd);
	close(fd);
	ft_make_area(lk, tet);
	return (0);
}
