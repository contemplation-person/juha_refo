CXX = c++
TARGET = megaphone
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $< -o $(TARGET)

all : $(TARGET)

clean : 
	@rm -f *.o

fclean : 
	@make clean
	@rm $(TARGET)

re :
	@make fclean
	make all
