/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Nov 10 04:57:18 2015 bastien penavayre
** Last update Thu Nov 12 11:19:09 2015 bastien penavayre
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

int		whileTest(Generator *this, int start, int end)
{
  int		i;

  init_yield();
  for (i = start; i < end; i++) {
    yield(i);
  }
  return -1;
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
  reset_generator(&tmp, NULL);

  newGen(&tmp, whileTest, 2, 7);
  while (tmp.isNotEmpty)
    printf("%d\n", popNew(int, &tmp));
  return (0);
}
