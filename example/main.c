/*
** main.c for  in /home/penava_b/perso/test/CYield
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Nov 29 02:32:09 2015 penava_b
** Last update Sun Nov 29 19:49:46 2015 penava_b
*/

#include <stdio.h>
#include "yield.h"

int		func(Generator *this, int val)
{
  int		i;

  initYield();
  yield(25);
  printf("argument is still : %d\n", val);
  for (i = 0; i < 5; i++)
    yield(5 + i);
  return (0XDEADB00B);
}

int		main()
{
  Generator    	gen;
  int		val;

  for_yield(&gen, func, val, 757)
    printf("%d\n", val);
  printf("Return value is %d\n", val);

  for_yield(0, func, val, 757)
    printf("Unreachable code\n");
  printf("Return value is %d\n", val);
  return 0;
}
