# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/09/19 18:28:05 by juha             ###   ########seoul.kr   #
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
				push_swap_utils/ret.c \
				sorting/hardcode.c \
				sorting/quick_hardcode.c \
				sorting/sort_stack.c \
				push_swap.c
				
OBJS	  	= 	$(SRC:.c=.o) 

.PHONY: all clean fclean re bonus


all:$(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean	all

test : $(OBJS_TEST) 
	$(CC) $(CPPFLAGS) $^ 