# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 10:39:58 by juha              #+#    #+#              #
#    Updated: 2022/08/28 20:48:55 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror
NAME 		= 	so_long
SRC 		= 	main.c \
				./parsing/error_utils.c \
				./parsing/parsing.c \
				./img_utils/img.c
OBJS		= 	$(SRC:.c=.o)
LIB_DIR		=	./libft


.PHONY: all clean fclean re bonus

%.o: %.c
	$(CC) $(CPPFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@make bonus -C $(LIB_DIR)
	@mv $(LIB_DIR)/libft.a ./libft.a
	$(CC) $(CPPFLAGS) $(OBJS) -L./ -lft -L./minilibx_opengl_20191021 -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
	
all: $(NAME)

bonus: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS) libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re : fclean all