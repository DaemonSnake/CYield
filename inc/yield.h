/*
** yield.h for  in /home/penava_b/perso/test/CYield
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Nov 29 02:28:03 2015 penava_b
** Last update Sun Nov 29 02:35:56 2015 penava_b
*/

#pragma once

#include <alloca.h>

typedef		struct
{
  void		*label;
  char		*stack;
  void		*func;
  char		alive;
  char		init;
  unsigned long	size;
}		Generator;

void    	__yield_editRet();
void		__yield_push_back(Generator *, const char *);
void		__yield_save_context(Generator *, const char *, const char *);
int		__fake_setjmp(Generator *);

#define initYield()						\
  if (this->label != NULL)					\
    {								\
      __yield_editRet();					\
      goto *this->label;					\
    }								\
  else								\
    this->alive = 0;

#define yield(val)						\
  if (__fake_setjmp(this) == 0)					\
    {								\
      __yield_save_context(this, alloca(0),			\
			   __builtin_frame_address(0));		\
      this->alive = 42;						\
      return val;						\
    }								\
  else								\
    {								\
      __yield_push_back(this, alloca(0));			\
      this->alive = 0;						\
    }

#define for_yield(x, Func, ret, args...)				\
  for ((x)->label = 0, (x)->func = Func, (x)->size = 0, (x)->stack = 0, (x)->alive = 42, ret = Func(x, args), (x)->init = 42; (x)->label != 0 && ((((x)->init) ? ((x)->init = 0) : (ret = ((__typeof__(ret)(*)(Generator *,...))((x)->func))((x)))), (x)->alive);)

