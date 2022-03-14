CC = cc
CFLAGES = -Wall -Wextra -Werror
NAME = libft.a
CINCLUDE = -I libft.h				
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c\
	  ft_isascii.c ft_isdigit.c ft_isprint.c\
	  ft_memcpy.c ft_memmove.c ft_memset.c\
	  ft_strlen.c ft_strlcpy.c
OBJS = $(SRC:.c=.o)

.PONY: all clean fclean re

all : $(NAME)

.c.o:
	$(CC) $(CFLAGES) -c $<

$(NAME) : $(OBJS)
	ar rcus $@ $^

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all