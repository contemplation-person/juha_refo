CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
TARGET		= convert 
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= main.cpp \
			  ScalarConverter.cpp
			  
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

