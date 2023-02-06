CXX 			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
TARGET		= phoneBook 
LIBCPPDIR = ../libCPP/
LIBCPP		= libCPP.a
OBJS			= $(SRCS:.c=.o)
SRCS 			= phoneBook.cpp
TESTFLAGS = -g3 -fsanitize=address


$(TARGET) : $(OBJS)
	@make -j4 -sC $(LIBCPPDIR)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(LIBCPPDIR)$(LIBCPP)

.PHONY : all clean fclean re

all : 
	$(TARGET)

clean : 
	@make clean -sC $(LIBCPPDIR)
	@rm -f *.o

fclean : 
	@make fclean -sC $(LIBCPPDIR)
	@make clean
	@rm -f $(TARGET)
	@rm -rf *.dSYM

re :
	@make fclean
	@make 

test : $(OBJS)
	@make -j4 -sC $(LIBCPPDIR)
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $^ -o $(TARGET) $(LIBCPPDIR)$(LIBCPP)
