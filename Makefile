# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkopiika <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 15:43:46 by mkopiika          #+#    #+#              #
#    Updated: 2019/03/14 16:43:44 by mkopiika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = fillit.h

SOURCE = main.c\
	 ft_valid.c\
	 ft_strsplit.c\
	 ft_spl_block.c\
	 ft_read_valid.c\
	 ft_print_area.c\
	 ft_make_link.c\
	 ft_make_area.c\
	 ft_fill_area.c\
	 ft_error.c\
	 ft_del_tetra.c\

FLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
