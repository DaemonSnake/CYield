##
## Makefile for  in /home/penava_b/perso/test
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Tue Nov 10 04:57:55 2015 bastien penavayre
## Last update Wed Nov 11 03:19:20 2015 bastien penavayre
##

SRC 	= main.c	\
	yield.c

OBJ	= $(SRC:.c=.o)

NAME	= test

CFLAGS = -W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ) yield.h
	gcc -o $(NAME) $(OBJ) -W -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
