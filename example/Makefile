##
## Makefile for  in /home/penava_b/perso/test/CYield/example
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Nov 29 02:56:52 2015 penava_b
## Last update Sun Nov 29 02:59:32 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		test

SRC =		main.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -I ../inc/

LDFLAGS =	$(COMMON) -Wl,-rpath=../ -L ../ -lYield

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C ../ all
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		$(MAKE) -C ../ clean
		$(RM) $(OBJ)

fclean: 	clean
		$(MAKE) -C ../ fclean
		$(RM) $(NAME)

re: 		fclean all
