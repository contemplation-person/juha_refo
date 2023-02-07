CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
AR				=	ar
TARGET		=	libCPP.a
ARFLAG		=	-rsc
SRCS			=	ftPrint.cpp ftCin.cpp
OBJS			=	$(SRCS:.cpp=.o)

$(TARGET) : $(OBJS)
	@$(AR) $(ARFLAG) $@ $^

all: $(TARGET)

clean:
	@rm -f $(OBJS) 

fclean : clean
	@rm -f $(TARGET)

re : 
	@make fclean 
	@make all
