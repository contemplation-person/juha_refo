# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/09/24 19:55:17 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror 
NAME		= 	push_swap	
SRC 		= 	push_swap_utils/init.c \
				push_swap_utils/cmd.c \
				push_swap_utils/cmd_utils.c \
				push_swap_utils/push_swap_error.c \
				push_swap_utils/push_swap_pre_code.c \
				sorting/hardcode.c \
				sorting/radix_sort.c \
				push_swap.c

OBJS		=	$(SRC:.c=.o)

.PHONY: all clean fclean re 	

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) -g3 $^ -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean	all
