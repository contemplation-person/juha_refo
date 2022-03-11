CC = cc
CFLAGS = -Wall -Werorre -Wextra
TARGET = libft.a
OBJS = ft_bzero.o ft_isalnum.o ft_isalnum.o 
SRCS = 
CINCLUDE = 

all : $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm -f *.o
	rm -f $(TARGET)

fclean : clean

re :
