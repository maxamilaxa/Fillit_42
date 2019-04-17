/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:43:07 by mkopiika          #+#    #+#             */
/*   Updated: 2019/04/10 15:57:12 by mkopiika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct		s_etra
{
	char			ltr;
	int				x[4];
	int				y[4];

	struct s_etra	*nxt;
	struct s_etra	*prv;
}					t_etra;

typedef	struct		s_pnt
{
	int				x;
	int				y;
	int				asize;
	char			ltr;
}					t_pnt;

typedef struct		s_iter
{
	int		i;
	int		j;
	int		f;
	int		cx;
	int		cy;
}					t_iter;

typedef struct		s_valid
{
	int		i;
	int		e;
	int		t;
	int		r;
	char	*ptr;
}					t_valid;

int					ft_spl_block(char *map);
void				ft_valid(char *s, int rd);
void				ft_error(int f);
int					ft_read_valid(int fd);
t_etra				*ft_make_link(int fd);
void				ft_make_area(t_etra *lk, int tet);
void				ft_print_area(char **area, int size);
void				ft_del_tetra(t_pnt p, char **area);
int					ft_fill_area(t_etra *lk, char **area, int size);
char				**ft_strsplit(char const *s, char c);
#endif
