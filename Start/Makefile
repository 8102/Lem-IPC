##
## Makefile for LemiPc in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
## 
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Sun Mar  1 22:01:01 2015 Johan Paasche
## Last update Mon Mar  2 01:16:10 2015 Johan Paasche
##

NAME		=	lemipc


CC		=	gcc
RM		=	rm -f

LINK		=	ln -fs


DEBUG		=	no

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic  -I$(INCLUDE_D) -lpthread -lSDL -lSDLmain -ldl -lSDL_image -lSDL_ttf -lSDL_mixer -D_GNU_SOURCE

ifeq			($(DEBUG),yes)
			CFLAGS += -g3
else
			CFLAGS += -O3
endif


SRC		=	main.c		\
			drawing.c	\

BIN_D		=	bin

OBJ_D		=	obj

INCLUDE_D	=	include

SRC_D		=	src

SRCS		= 	$(addprefix $(SRC_D)/, $(SRC))

PRO		= 	$(addprefix $(BIN_D)/, $(NAME))

OBJS		= 	$(addsuffix .o, $(basename $(subst $(SRC_D), $(OBJ_D), $(SRCS))))

FIRST		:=	$(shell test -d $(OBJ_D) || mkdir $(OBJ_D))	\
			$(shell test -d $(BIN_D) || mkdir $(BIN_D))

$(NAME)		:	$(PRO)
		 	@$(LINK) $(PRO) $(NAME)

$(OBJ_D)/%.o	:	$(SRC_D)/%.c
		 	$(CC) $(CFLAGS) -c $< -o $@

$(PRO)		: 	$(OBJS)
		  	$(CC) $(CFLAGS) $(OBJS) -o $(PRO)

all		:	$(NAME)

clean		:
		  	$(RM)		$(OBJS)

fclean		: 	clean
		  	$(RM)		$(PRO)
		  	$(RM)		$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
