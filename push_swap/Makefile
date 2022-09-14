# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/09/14 19:53:34 by juha             ###   ########seoul.kr   #
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
				sorting/sort_stack.c \
				push_swap.c

TEST		=	test.c
				
SRC_BONUS	=	
				
OBJS_BONUS	= 	$(SRC_BONUS:.c=.o)
OBJS_TEST  	=  	$(SRC:.c=.o) $(TEST:.c=.o) $(SRC_BONUS:.c=.o)
OBJS	  	= 	$(SRC:.c=.o) 

.PHONY: all clean fclean re bonus

ifeq ($(MAKECMDGOALS), bonus)	
$(NAME): $(OBJS) $(OBJS_BONUS)
	$(CC) $(CPPFLAGS) $(NAME) $^
else
$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $@ $^
endif

all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : 
	fclean 
	all

test : $(OBJS_TEST) 
	$(CC) $(CPPFLAGS) $^ 