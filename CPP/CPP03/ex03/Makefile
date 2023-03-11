CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
TARGET		= ScavTrap 
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp \
			  DiamondTrap.cpp 
TESTFLAGS 	= -g3 -fsanitize=address

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

test : $(OBJS)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $^ -o $(TARGET)
