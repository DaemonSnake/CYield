/*
** yield.h for  in /home/penava_b/perso/test/CYield
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Nov 29 02:28:03 2015 penava_b
** Last update Mon Nov 30 11:15:32 2015 penava_b
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
char		__yield_continue(Generator *);
Generator	*__yield_init(Generator *, void *);

#define initYield()						\
  if (this != NULL && this->label != NULL)			\
    {								\
      __yield_editRet();					\
      goto *this->label;					\
    }								\
  else								\
    {								\
      if (this != NULL)						\
	{							\
	  this->alive = 0;					\
	  this->init = 42;					\
	}							\
    }

#define yield(val)						\
  if (__fake_setjmp(this) == 0)					\
    {								\
      if (this->init)						\
	{							\
	  __yield_save_context(this, alloca(0),			\
			       __builtin_frame_address(0));	\
	  this->alive = 42;					\
	}							\
      return val;						\
    }								\
  else								\
    {								\
      if (this != NULL)						\
	{							\
	  __yield_push_back(this, alloca(0));			\
	  this->alive = 0;					\
	}							\
    }

#define for_yield(x, Func, ret, args...)				\
  for (ret = Func(__yield_init(x, Func), args);				\
       __yield_continue(x);						\
       ret = ((__typeof__(ret)(*)(Generator *,...))(((Generator *)x)->func))((x)))
