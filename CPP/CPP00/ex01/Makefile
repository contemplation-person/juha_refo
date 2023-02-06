CXX 			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
TARGET		= phoneBook 
LIBCPPDIR = ../libCPP/
LIBCPP		= libCPP.a
OBJS			= $(SRCS:.c=.o)
	SRCS 			= phoneBook.cpp


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
	@rm $(TARGET)

re :
	@make fclean
	@make 
