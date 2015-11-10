##
## Makefile for  in /home/penava_b/perso/test
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Tue Nov 10 04:57:55 2015 bastien penavayre
## Last update Tue Nov 10 22:24:02 2015 bastien penavayre
##

SRC 	= main.c	\
	yield.c

OBJ	= $(SRC:.c=.o)

NAME	= test

CFLAGS = -g3

all:	$(NAME)

$(NAME): $(OBJ) yield.h
	gcc -o $(NAME) $(OBJ) -W -Wall -Wextra -Werror -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
