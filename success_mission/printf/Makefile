# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/05/30 15:47:28 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror 
NAME		= 	libftprintf.a
SRC 		= 	ft_printf.c \
				ft_printf_num_util.c \
				ft_printf_str_util.c \
				ft_printf_libft_util.c \
				
AR			= 	ar
ARFLAG		= 	rsc
OBJS	  	= 	$(SRC:.c=.o)

.PHONY : all clean fclean re t

$(NAME) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS) 

fclean : clean
	rm -f $(NAME) a.out

re : fclean all

t : $(NAME) test.c
	$(CC) $(CPPFLAGS)test.c $(SRC) -g3 -fsanitize=address
	rm -f *.o *.a
