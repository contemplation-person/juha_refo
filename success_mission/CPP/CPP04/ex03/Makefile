CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address -Wno-shadow -MMD
TARGET		= Game
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(SRCS:.cpp=.d)
SRCS 		= $(wildcard *.cpp)

			  
TESTFLAGS 	= -g3 -fsanitize=address

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) 

.PHONY : all clean fclean re

all : 
	$(TARGET)

clean : 
	@rm -f *.o *.d

fclean : 
	@make clean
	@rm -f $(TARGET)
	@rm -rf *.dSYM

re :
	@make fclean
	@make 

test : $(OBJS)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $^ -o $(TARGET)

-include $(DEPS)
