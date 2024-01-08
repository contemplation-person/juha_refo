CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3
TARGET		= btc
OBJS		= $(SRCS:.cpp=.o)
SRCS 		= main.cpp \
			  BitcoinExchange.cpp
			  
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) 

.PHONY : all clean fclean re

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

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

