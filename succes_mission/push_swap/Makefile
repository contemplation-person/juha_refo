# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2023/01/14 08:40:34 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
#CFLAGS	= 	-Wall -Wextra -Werror
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
NAME		= 	push_swap
SRC			=	push_swap_utils/archive.c \
				push_swap_utils/cmd_a.c \
				push_swap_utils/cmd_b.c \
				push_swap_utils/ft_split.c \
				push_swap_utils/init.c \
				push_swap_utils/push_swap_error.c \
				push_swap_utils/push_swap_pre_code.c \
				sorting/hardcode.c \
				sorting/sort.c \
				push_swap.c \
				test.c
				
OBJS		=	$(SRC:.c=.o)

.PHONY: all clean fclean re 

all : $(NAME)

$(NAME) : $(OBJS) $(TSRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f $(OBJS)

fclean : 
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all
