CC = cc
CFLAGES = -Wall -Wextra -Werror
NAME = libft.a					
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c\
	  ft_isascii.c ft_isdigit.c ft_isprint.c\
	  ft_memcpy.c ft_memmove.c ft_memset.c\
	  ft_strlen.c ft_strlcpy.c ft_toupper.c\
	  ft_tolower.c ft_strncmp.c ft_strlcat.c\
	  ft_strchr.c ft_strrchr.c

OBJS = $(SRC:.c=.o)

.PONY: all clean fclean re

all : $(NAME)

$(OBJS):$(SRC)
	$(CC) $(CFLAGES) -c $^

$(NAME) : $(OBJS)
	ar rcus $@ $^

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all