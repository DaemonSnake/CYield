##
## Makefile for  in /home/penava_b/perso/test/CYield
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Nov 29 02:55:46 2015 penava_b
## Last update Sun Jun  5 17:59:39 2016 penava_b
##

CC =		gcc
RM =		rm -f
SHARED =	libYield.so
STATIC =	libYield.a
SRC =		src/yield.c
OBJ =		$(SRC:.c=.o)
COMMON =	-W -Wall -Werror -Wextra
CFLAGS =	$(COMMON) -fPIC -I inc/
LDFLAGS =	$(COMMON) -shared

all: 		$(SHARED)

$(SHARED): 	$(OBJ)
		$(CC) $(OBJ) -o $(SHARED) $(LDFLAGS)

$(STATIC):	$(OBJ)
		@ar -cq $@ $<

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(SHARED) $(STATIC)

re: 		fclean all
