/*
** yield.h for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Nov 10 04:28:17 2015 bastien penavayre
** Last update Tue Nov 10 23:10:02 2015 bastien penavayre
*/

#pragma once

#include <stdlib.h>

typedef		struct
{
  char		*buff;
  size_t	size;
  void		*label;
  char		isNotEmpty;
  void		*func;
  void		*funcId;
}		Generator;

void		__yield_save_stack(Generator *, const char *, const char *);
void		__yield__pop_stack_back(Generator *, const char *);
void		reset_generator(Generator *, void *);
void		__yield__exit_error();

#define init_yield()							\
  register const char *rbp asm("rbp");					\
  register const char *rsp asm("rsp");					\
__yield__init_label:							\
 if (this->funcId == NULL) {						\
   reset_generator(this, &&__yield__init_label);			\
   __yield_save_stack(this, rsp, rbp);					\
   this->isNotEmpty = 42;						\
   return ;								\
 }									\
 if (this->funcId != &&__yield__init_label)				\
   __yield__exit_error();						\
 __yield__pop_stack_back(this, rsp);					\
 this->isNotEmpty = 0;							\
 if (this->label != NULL)						\
   goto *this->label;

#define HASH(x, y) x ## y

#define newLabel(line)				\
  HASH(__yield__, line)

#define LabelSymb(label) label :

#define yield(val...)							\
  return (__yield_save_stack(this, rsp, rbp),				\
	  this->label = &&newLabel(__LINE__),				\
	  this->isNotEmpty = 42,					\
	  (val));							\
  LabelSymb(newLabel(__LINE__));					\
  this->label = NULL;

#define newGen(gen, f, args...)						\
  (void)((gen)->buff = NULL, (gen)->isNotEmpty = 42,			\
	 (gen)->func = f, (gen)->funcId = NULL,				\
	 f(gen, ##args))

#define popNew(type, gen) (((type(*)(Generator*, ...))(gen)->func)(gen))
