# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/05/25 14:33:04 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror -g3
NAME		= 	ft_printf.a	
SRC 		= 	ft_printf.c \
				ft_printf_write_util.c \
				ft_printf_util.c \
				ft_printf_libft_util.c \
				
AR			= 	ar
ARFLAG		= 	rscu
OBJS	  	= 	$(SRC:.c=.o)

.PHONY: all clean fclean re bonus

$(NAME) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME)

re : fclean all
test: $(NAME) test.c
	gww test.c ft_printf.a -g3
