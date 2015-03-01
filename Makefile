##
## Makefile for lemipc in /home/patoche/rendu/Unix/PSU_2014_lemipc
##
## Made by Hugo Prenat
## Login   <prenat_h@epitech.eu>
##
## Started on  Wed Feb 25 21:41:59 2015 Hugo Prenat
## Last update Sun Mar  1 06:42:48 2015 Johan Paasche
##

SRC		=	test.c

OBJ		=	$(SRC:.c=.o)

NAME		=	lemipc

CC		=	gcc

RM		=	rm -f

DEBUG		=	yes

INCLUDE 	=	includes/

CFLAGS		=	-W -Wall -Wextra -Werror -I $(INCLUDE) -pthread 

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
