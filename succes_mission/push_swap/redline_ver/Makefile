# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2023/01/16 15:12:50 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CFLAGS		= 	-Wall -Wextra -Werror
NAME		= 	push_swap
BONUS_NAME	= 	checker
COMMON_SRC 	= 	push_swap_utils/init.c \
				push_swap_utils/init2.c \
				push_swap_utils/ft_split.c \
				push_swap_utils/cmd_utils.c \
				push_swap_utils/push_swap_error.c \
				push_swap_utils/push_swap_pre_code.c\
				push_swap_utils/common_utils.c
SORTING_SRC	=	sorting/hardcode.c \
				sorting/sorting_utils.c \
				sorting/redline_sort.c \
				push_swap_utils/cmd.c \
				push_swap.c
BONUS_SRC	=	push_swap_utils/gnl_utils_bonus.c\
				push_swap_utils/cmd_bonus.c \
				push_swap_utils/gnl_bonus.c \
				push_swap_utils/ft_strncmp_bonus.c \
				checker.c

COMMON_OBJS	=	$(COMMON_SRC:.c=.o)
SORTING_OBJS=	$(SORTING_SRC:.c=.o)
OBJS_BONUS	=	$(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re

ifeq ($(MAKECMDGOALS), bonus)	
$(NAME) : $(BONUS_SRC) $(COMMON_SRC)
		$(CC) $(CFLAGS) -Ipush_swap $^ -o $(BONUS_NAME)
else
$(NAME) : $(COMMON_SRC) $(SORTING_OBJS)
		$(CC) $(CFLAGS) -Ipush_swap $^ -o $(NAME)
endif
	
all : $(NAME)

bonus : $(NAME)

clean:
	rm -f *.o */*.o

fclean : 
	make clean
	rm -f $(NAME) $(BONUS_NAME)

re : 
	make fclean
	make all
