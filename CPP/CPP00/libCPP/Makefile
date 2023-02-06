CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
AR				=	ar
TARGET		=	libCPP.a
ARFLAG		=	-rsc
SRCS			=	ftPrint.cpp
OBJS			=	$(SRCS:.cpp=.o)

$(TARGET) : $(OBJS)
	$(AR) $(ARFLAG) $@ $^

all: $(TARGET)

bonus: $(TARGET)

clean:
	@rm -f $(OBJS) 

fclean : clean
	@rm -f $(TARGET)

re : 
	@make fclean 
	@make all
