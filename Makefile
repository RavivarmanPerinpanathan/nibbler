##
## Makefile for make in /home/perinp_r/rendu/cpp_nibbler
## 
## Made by ravivarman perinpanathan
## Login   <perinp_r@epitech.net>
## 
## Started on  Sun Apr  5 22:04:57 2015 ravivarman perinpanathan
## Last update Sun Apr  5 22:04:59 2015 ravivarman perinpanathan
##

CC		=	g++

RM		=	rm -f

CXXFLAGS	+=	-W -Wextra -Wall -Werror -fPIC

LDFLAGSL1	=	-lSDL

LDFLAGSL2	=	-lSDL -lGL -lGLU

LDFLAGSL3	=	-lncurses -lpthread

NAME            =       nibbler

NAMEL1          =       libmy_sdl_${HOSTTYPE}.so

NAMEL2		=	libmy_glu_${HOSTTYPE}.so

NAMEL3		=	libmy_ncurse_${HOSTTYPE}.so


SRCS            =       main.cpp \
                        Nibbler.cpp \
                        Coordinates.cpp

SRCSL1		=	SDL_lib/LibSDL.cpp

SRCSL2		=	GL_lib/LibGL.cpp

SRCSL3		=	Ncurse_lib/Ncurse.cpp


OBJS		=	$(SRCS:.cpp=.o)

OBJSL1		=	$(SRCSL1:.cpp=.o)

OBJSL2		=	$(SRCSL2:.cpp=.o)

OBJSL3		=	$(SRCSL3:.cpp=.o)

all		:	$(NAME) $(NAMEL1) $(NAMEL2) $(NAMEL3)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -ldl

$(NAMEL1)	:	$(OBJSL1)
			$(CC) $(CXXFLAGS) -c $(SRCSL1) $(LDFLAGSL1)
			$(CC) $(OBJSL1) -o $(NAMEL1) -shared $(LDFLAGSL1)

$(NAMEL2)	:	$(OBJSL2)
			$(CC) $(CXXFLAGS) -c $(SRCSL2) $(LDFLAGSL2)
			$(CC) $(OBJSL2) -o $(NAMEL2) -shared $(LDFLAGSL2)

$(NAMEL3)       :       $(OBJSL3)
			$(CC) $(CXXFLAGS) -c $(SRCSL3) $(LDFLAGSL3)
			$(CC) $(OBJSL3) -o $(NAMEL3) -shared $(LDFLAGSL3)

clean		:
			$(RM) $(OBJS) $(OBJSL1) $(OBJSL2) $(OBJSL3) *.o

fclean		:	clean
			$(RM) $(NAME) $(NAMEL1) $(NAMEL2) $(NAMEL3)

re		:	fclean all

.PHONY		:	all clean fclean re
