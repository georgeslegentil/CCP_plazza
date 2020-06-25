##
## EPITECH PROJECT, 2020
## CCP_plazza_2019
## File description:
## Makefile
##

CXX		= 	g++

SRCS		=	./src/main.cpp \
	  		./src/error.cpp \
			./src/Kitchen/Busy.cpp \
			./src/Kitchen/Command.cpp \
			./src/Kitchen/Cook.cpp \
			./src/Kitchen/Cooking.cpp \
			./src/Kitchen/Ingredients.cpp \
			./src/Kitchen/Kitchen.cpp \
			./src/Reception/Reception.cpp \
			./src/IPC/IPC.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	=	plazza

CXXFLAGS = -Wall -Wextra -std=c++17

CPPFLAGS = -I include/
THREADFLAGS	= -lpthread -lrt

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(THREADFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
