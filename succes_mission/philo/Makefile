# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:57:00 by juha              #+#    #+#              #
#    Updated: 2022/11/15 21:44:47 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CFLAGES 	= 	-Wall -Werror -Wextra
NAME 		= 	philo
SRC 		= 	./basic/utils.c \
				./basic/parsing.c \
				./basic/init.c \
				operate.c \
				philo.c \
				thread.c \
				time.c
				
OBJS 		=	$(SRC:.c=.o)

.PHONY: all clean fclean re

$(NAME) : $(OBJS)
			$(CC) $(CFLAGES) -Iphilo $^ -o $(NAME)

all : $(NAME)

clean : 
	@rm -rf *.o */*.o

fclean :
	@make clean
	@rm -rf $(NAME)

re :
	@make fclean
	@make all
