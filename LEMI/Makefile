##
## Makefile for LemiPc in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
## 
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Sun Mar  1 22:01:01 2015 Johan Paasche
## Last update Tue Mar  3 02:01:04 2015 Johan Paasche
##

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

INCLUDE_D	=	include

##______________________________________________##
##						##
##		   EXECUTABLE			##
##______________________________________________##
##						##

NAME		=	lemipc

SRC		=	main.c		\
			drawing.c	\

BIN_D		=	bin

OBJ_D		=	obj

SRC_D		=	src

SRCS		= 	$(addprefix $(SRC_D)/, $(SRC))

PRO		= 	$(addprefix $(BIN_D)/, $(NAME))

OBJS		= 	$(addsuffix .o, $(basename $(subst $(SRC_D), $(OBJ_D), $(SRCS))))

##______________________________________________##
##						##
##		CLIENT GRAPHIQUE		##
##______________________________________________##
##						##

GRAPHIC_NAME	=	lemi_display

GRAPHIC_SRC	=	graphic_client.c	\
			drawing.c		\

GRAPHIC_SRC_D	=	graphic_src

GRAPHIC_SRCS	=	$(addprefix $(GRAPHIC_SRC_D)/, $(GRAPHIC_SRC))

GRAPHIC_PRO	=	$(addprefix $(BIN_D)/, $(GRAPHIC_NAME))

GRAPHIC_OBJS	=	$(addsuffix .o, $(basename $(subst $(GRAPHIC_SRC_D), $(OBJ_D), $(GRAPHIC_SRCS))))


##______________________________________________##
##						##
##		     REGLES			##
##______________________________________________##
##						##

FIRST		:=	$(shell test -d $(OBJ_D) || mkdir $(OBJ_D))	\
			$(shell test -d $(BIN_D) || mkdir $(BIN_D))

all		:	$(NAME) $(GRAPHIC_NAME)


$(GRAPHIC_NAME)	:	$(GRAPHIC_PRO)
			@$(LINK) $(GRAPHIC_PRO) $(GRAPHIC_NAME)

$(OBJ_D)/%.o	:	$(GRAPHIC_SRC_D)/%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(GRAPHIC_PRO)	:	$(GRAPHIC_OBJS)
			$(CC) $(CFLAGS) $(GRAPHIC_OBJS) -o $(GRAPHIC_PRO)


$(NAME)		:	$(PRO)
		 	@$(LINK) $(PRO) $(NAME)

$(OBJ_D)/%.o	:	$(SRC_D)/%.c
		 	$(CC) $(CFLAGS) -c $< -o $@

$(PRO)		: 	$(OBJS)
		  	$(CC) $(CFLAGS) $(OBJS) -o $(PRO)


clean		:
		  	$(RM)		$(OBJS) $(GRAPHIC_OBJS)

fclean		: 	clean
		  	$(RM)		$(PRO) $(GRAPHIC_PRO)
		  	$(RM)		$(NAME) $(GRAPHIC_NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
