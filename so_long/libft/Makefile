# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 17:12:04 by juha              #+#    #+#              #
#    Updated: 2022/08/28 20:49:35 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CPPFLAGS	= 	-Wall -Wextra -Werror
NAME		= 	libft.a	
SRC 		= 	ft_bzero.c ft_isalnum.c ft_isalpha.c\
				ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_strlen.c ft_strlcpy.c ft_toupper.c\
				ft_tolower.c ft_strncmp.c ft_strlcat.c\
				ft_strchr.c ft_strrchr.c ft_memchr.c\
				ft_memcmp.c ft_strnstr.c ft_atoi.c\
				ft_calloc.c ft_strdup.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_striteri.c get_next_line.c get_next_line_utils.c
				
SRC_BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c\
				
AR			= 	ar
ARFLAG		= 	rscu
OBJS	  	= 	$(SRC:.c=.o)
OBJS_BONUS	= 	$(SRC_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

ifeq ($(MAKECMDGOALS), bonus)	
$(NAME): $(OBJS) $(OBJS_BONUS)
	@$(AR) $(ARFLAG) $(NAME) $^
else
$(NAME) : $(OBJS)
	@$(AR) $(ARFLAG) $@ $^
endif

all: $(NAME)

bonus: $(NAME)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
