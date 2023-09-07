CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -MMD
TARGET		= Animal
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= $(wildcard *.cpp)
DEPT		= $(SRCS:.cpp=.d)
			  
TESTFLAGS 	= -g3 -fsanitize=address

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) 

.PHONY : all clean fclean re

all : 
	$(TARGET)

clean : 
	@rm -f *.d
	@rm -f *.o

fclean : 
	@make clean
	@rm -f $(TARGET)
	@rm -rf *.dSYM

re :
	@make fclean
	@make 

test : $(OBJS)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $^ -o $(TARGET)

-include $(DEPT)
