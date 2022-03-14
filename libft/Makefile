CC = cc
CFLAGES = -Wall -Wextra -Werror
TARGET = libft.a
CINCLUDE = -I libft.h				
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c\
	  ft_isascii.c ft_isdigit.c ft_isprint.c\
	  ft_memcpy.c ft_memmove.c ft_memset.c\
	  ft_strlen.c
OBJS = $(SRC:.c=.o)

.PONY: all clean fclean re

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGES) -c $<

$(TARGET) : $(OBJS)
	ar rcus $(TARGET) $(OBJS)

clean:
	rm *.o
	rm $(TARGET)

fclean : clean all

re : fclean all