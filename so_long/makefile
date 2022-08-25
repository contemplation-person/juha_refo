# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 10:39:58 by juha              #+#    #+#              #
#    Updated: 2022/08/25 16:32:29 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror
NAME 		= 	so_long
SRC 		= 	so_long.c
OBJS		= 	$(SRC:.c=.o)
LIB_DIR		=	./libft


.PHONY: all clean fclean re bonus

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@make bonus -C $(LIB_DIR)
	@mv $(LIB_DIR)/libft.a ./libft.a
	$(CC) $(CPPFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
	
all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all