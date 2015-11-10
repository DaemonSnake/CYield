/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Nov 10 04:57:18 2015 bastien penavayre
** Last update Tue Nov 10 19:19:42 2015 bastien penavayre
*/

#include <stdio.h>
#include "yield.h"

int		func(Generator *this)
{
  init_yield();

  int		i;
  double	b;
  float		f;

  i = 52;
  b = 152.25;
  f = 35.0;
  printf("Before yield\n");
  yield(52);
  i *= 2;
  printf("After yield : %d %f %f\n", i, b, f);
  return f;
}

int		main(void)
{
  Generator	tmp;
  int		res[2];
  int		i = 0;

  newGen(&tmp, func);
  while (tmp.isNotEmpty)
    res[i++] = popNew(int, &tmp);
  printf("results : {%d} {%d}\n", res[0], res[1]);
}
