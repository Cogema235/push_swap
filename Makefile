# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nomoulin <nomoulin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 11:31:21 by nomoulin          #+#    #+#              #
#    Updated: 2023/02/10 14:14:57 by nomoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang
CFLAGS = -fsanitize=address #-Wall -Wextra -Werror

CFILES = errors main tests check init push_swap utils
OBJS = $(addsuffix .o, $(CFILES))

all : $(NAME)

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY : all fclean clean re