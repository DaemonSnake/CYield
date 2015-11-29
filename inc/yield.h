/*
** yield.h for  in /home/penava_b/perso/test/CYield
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Nov 29 02:28:03 2015 penava_b
** Last update Sun Nov 29 19:48:29 2015 penava_b
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
void		*__yield_return_value(void *);

#define initYield()						\
  if (this != NULL && this->label != NULL)			\
    {								\
      __yield_editRet();					\
      goto *this->label;					\
    }								\
  else								\
    {								\
      if (this != NULL)						\
	this->alive = 0;					\
    }

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
      if (this != NULL)						\
	{							\
	  __yield_push_back(this, alloca(0));			\
	  this->alive = 0;					\
	}							\
    }

#define for_yield(x, Func, ret, args...)				\
  for (__yield_return_value(x) != 0 ?					\
	 (((Generator *)x)->label = 0,					\
	  ((Generator *)x)->func = Func,				\
	  ((Generator *)x)->size = 0,					\
	  ((Generator *)x)->stack = 0,					\
	  ((Generator *)x)->alive = 42,					\
	  ret = Func(x, args),						\
	  ((Generator *)x)->init = 42)					\
	 : (ret = Func(0, args), 42);					\
       __yield_return_value(x) != 0 &&					\
	 ((Generator *)x)->label != 0 &&				\
	 (((((Generator *)x)->init) ?					\
	   (((Generator *)x)->init = 0)					\
	   : (ret = ((__typeof__(ret)(*)(Generator *,...))(((Generator *)x)->func))((x)))), ((Generator *)x)->alive);)
