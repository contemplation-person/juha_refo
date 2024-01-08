# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:57:00 by juha              #+#    #+#              #
#    Updated: 2024/01/08 14:09:30 by juha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CFLAGES 	= 	-Wall -Werror -Wextra
NAME 		= 	pipex
SRC 		= 	pipex.c utils.c operation.c 
BONUS_SRC 	=	here_doc_bonus.c pipex_bonus.c operation_bonus.c utils_bonus.c
LIBFT		=	libft.a
LIB_DIR 	=	./libft
OBJS 		=	$(SRC:.c=.o)
BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re bonus

ifeq ($(MAKECMDGOALS), bonus)	
$(NAME) : $(BONUS_OBJS) 
		@make bonus -C $(LIB_DIR)
		$(CC) $(CFLAGES) -L./libft -lft -Ilibft $^ -o $(NAME)
else
$(NAME) : $(OBJS)
		@make bonus -C $(LIB_DIR)
		$(CC) $(CFLAGES) -L./libft -lft -Ilibft $^ -o $(NAME)
endif

all : $(NAME)

bonus : $(NAME)

clean : 
	@rm -rf *.o
	@make clean -C $(LIB_DIR)

fclean :
	@make clean
	@rm -rf $(NAME) $(LIBFT)
	@make fclean -C $(LIB_DIR)

re :
	@make fclean
	@make all
