CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address
TARGET		= whatever 
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= main.cpp
			  
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) 

.PHONY : all clean fclean re

all : 
	$(TARGET)

clean : 
	@rm -f *.o

fclean : 
	@make clean
	@rm -f $(TARGET)
	@rm -rf *.dSYM

re :
	@make fclean
	@make 

