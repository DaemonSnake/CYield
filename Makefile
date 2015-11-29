##
## Makefile for  in /home/penava_b/perso/test/CYield
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Nov 29 02:55:46 2015 penava_b
## Last update Sun Nov 29 02:58:26 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		libYield.so

SRC =		yield.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -fPIC -I inc/

LDFLAGS =	$(COMMON) -shared

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
