CXX 		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 #-fsanitize=address -Wno-shadow
TARGET		= Animal
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= main.cpp \
			  Animal.cpp \
			  Dog.cpp \
			  Cat.cpp \
			  Brain.cpp
			  
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
