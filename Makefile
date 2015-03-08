##
## Makefile for LemiPc in /home/paasch_j/work/PSU/PSU_2014_lemipc/Start
## 
## Made by Johan Paasche
## Login   <paasch_j@epitech.net>
## 
## Started on  Sun Mar  1 22:01:01 2015 Johan Paasche
## Last update Sun Mar  8 20:52:37 2015 Hugo Prenat
##

CC		=	gcc

RM		=	rm -f

LINK		=	ln -fs


DEBUG		=	yes

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic  -I$(INCLUDE_D) -lpthread $(SDL_LIB) -D_GNU_SOURCE

INCLUDE_D	=	include

BIN_D		=	bin

OBJ_D		=	obj

SDL_LIB		=	-lSDL -lSDLmain -ldl -lSDL_image -lSDL_ttf -lSDL_mixer

##______________________________________________##
##						##
##		   EXECUTABLE			##
##______________________________________________##
##						##

NAME		=	lemipc

SRC		=	main.c		\
			is_alive.c	\
			move.c		\
			check_map.c	\
			enemy.c		\
			signal.c	\
			status_sem.c

SRC_D		=	src

SRCS		= 	$(addprefix $(SRC_D)/, $(SRC))

PRO		= 	$(addprefix $(BIN_D)/, $(NAME))

OBJS		= 	$(addsuffix .o, $(basename $(subst $(SRC_D), $(OBJ_D), $(SRCS))))

EXEC_CFLAGS	=	$(CFLAGS) -D_GNU_SOURCE

##______________________________________________##
##						##
##		CLIENT GRAPHIQUE		##
##______________________________________________##
##						##

GRAPHIC_NAME	=	gui_lemipc

GRAPHIC_SRC	=	graphic_client.c	\
			drawing.c		\
			init_colour_array.c	\
			manage.c		\
			text.c			\

GRAPHIC_SRC_D	=	graphic_src

GRAPHIC_SRCS	=	$(addprefix $(GRAPHIC_SRC_D)/, $(GRAPHIC_SRC))

GRAPHIC_PRO	=	$(addprefix $(BIN_D)/, $(GRAPHIC_NAME))

GRAPHIC_OBJS	=	$(addsuffix .o, $(basename $(subst $(GRAPHIC_SRC_D), $(OBJ_D), $(GRAPHIC_SRCS))))

GRAPHIC_CFLAGS	=	$(EXEC_FLAGS) -lpthread $(SDL_LIB)

##______________________________________________##
##						##
##		     REGLES			##
##______________________________________________##
##						##

ifeq			($(DEBUG),yes)
			CFLAGS += -g3
else
			CFLAGS += -O3
endif


FIRST		:=	$(shell test -d $(OBJ_D) || mkdir $(OBJ_D))	\
			$(shell test -d $(BIN_D) || mkdir $(BIN_D))

$(NAME)		:	$(PRO)
		 	@$(LINK) $(PRO) $(NAME)


$(OBJ_D)/%.o	:	$(SRC_D)/%.c
		 	$(CC) $(EXEC_CFLAGS) -c $< -o $@

$(PRO)		: 	$(OBJS)
			@echo -e "\033[34m" "Compiling Binary" "\033[0m"
		  	$(CC) $(CFLAGS) $(OBJS) -o $(PRO)


$(GRAPHIC_NAME)	:	$(GRAPHIC_PRO)
			@$(LINK) $(GRAPHIC_PRO) $(GRAPHIC_NAME)

$(OBJ_D)/%.o	:	$(GRAPHIC_SRC_D)/%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(GRAPHIC_PRO)	:	$(GRAPHIC_OBJS)
			@echo -e "\033[34m" "Compiling GUI" "\033[0m"
			$(CC) $(GRAPHIC_CFLAGS) $(GRAPHIC_OBJS) -o $(GRAPHIC_PRO)

all		:	$(NAME) $(GRAPHIC_NAME)


clean		:
		  	$(RM)		$(OBJS) $(GRAPHIC_OBJS)

fclean		: 	clean
		  	$(RM)		$(PRO) $(GRAPHIC_PRO)
		  	$(RM)		$(NAME) $(GRAPHIC_NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re
