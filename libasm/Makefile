# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/10/13 14:20:03 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
NAME            = libasm.a
SRCS            = ft_strlen.s \
		  ft_strcmp.s \
		  ft_strcpy.s
		
OBJS            = $(SRCS:.s=.o)

AR              = ar
ARFLAGS         = rcs

.PHONY: all clean fclean re bonus

%.o: %.s
	@nasm -f elf64 $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
