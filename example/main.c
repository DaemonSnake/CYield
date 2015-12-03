/*
** main.c for  in /home/penava_b/perso/test/CYield
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Nov 29 02:32:09 2015 penava_b
** Last update Thu Dec  3 15:47:36 2015 penava_b
*/

#include <stdio.h>
#include <stdlib.h>
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

int		yieldYielder(Generator *this)
{
  Generator	gen;
  int		val;
  
  initYield();
  yield(0);
  yield(103);
  for_yield(&gen, func, val, 757)
    yield(val);
  return 0;
}

int		main()
{
  Generator    	gen;
  int		val;

  // Default test
  for_yield(&gen, func, val, 757) {
    printf("%d\n", val);
  }
  
  printf("Return value is %d\n", val);

  printf("\n");

  // NULL generator test
  for_yield(0, func, val, 757)
    printf("Unreachable code\n");
  printf("Return value is %d\n", val);

  printf("\n");

  // Leak test break
  for_yield(&gen, func, val, 757)
    {
      printf("%d\n", val);
      if (val == 6)
  	yield_interupt(&gen) break;
    }

  printf("\n");

  // Leak test exit
  for_yield(&gen, func, val, 757)
    {
      printf("%d\n", val);
      if (val == 6)
  	yield_interupt(&gen) exit(5);
    }

  printf("\n");

  // yield in yield func
  for_yield(&gen, yieldYielder, val)
    printf("%d\n", val);
  return 0;
}
