# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2023/01/08 04:08:11 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror 
NAME		= 	push_swap	
SRC 		= 	push_swap_utils/init.c \
				push_swap_utils/ft_split.c \
				push_swap_utils/cmd.c \
				push_swap_utils/cmd_utils.c \
				push_swap_utils/push_swap_error.c \
				push_swap_utils/push_swap_pre_code.c \
				sorting/hardcode.c \
				sorting/radix_sort.c \
				push_swap.c

OBJS		=	$(SRC:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

clean:
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all
