/*
1;2802;0c** gctest.c for  in /home/penava_b/perso/test
**
** Made by penava_b
** Login   <penava_b@epitech.net>
**
** Started on  Sat Nov 28 02:32:38 2015 penava_b
** Last update Mon Nov 30 11:55:24 2015 penava_b
*/

#include <stdlib.h>
#include "yield.h"

int		__fake_setjmp(Generator *this)
{
  if (this == NULL)
    return -1;
  this->label = __builtin_return_address(0);
  return 0;
}

void		__yield_save_context(Generator *this, const char *rsp, const char *rbp)
{
  size_t       	i;

  if (this == NULL || rsp == NULL || rbp == NULL)
    return ;
  if (this->size != 0)
    free(this->stack);
  this->stack = NULL;
  this->size = 0;
  if ((this->stack = malloc(rbp - rsp)) == NULL)
    return ;
  this->size = rbp - rsp;
  for (i = 0; i < this->size; i++)
    this->stack[i] = rsp[i];
}

void		__yield_push_back(Generator *this, const char *rsp)
{
  size_t       	i;

  if (this == NULL || this->stack == NULL || rsp == NULL)
    return ;
  for (i = 0; i < this->size; i++)
    ((char *)rsp)[i] = this->stack[i];
  free(this->stack);
  this->stack = 0;
  this->size = 0;
}

__asm(".globl __yield_editRet\n\t"
      ".type __yield_editRet, @function\n\t"
      "__yield_editRet:\n\t"
      "push %rbp\n\t"
      "mov %rsp,%rbp\n\t"
      "mov $0x42, %eax\n\t"
      "pop %rbp\n\t"
      "retq");

Generator	*__yield_init(Generator *this, void *func)
{
  if (this == NULL)
    return this;
  this->label = 0;
  this->func = func;
  this->size = 0;
  this->stack = 0;
  this->alive = 42;
  this->init = 0;
  return this;
}

char		__yield_continue(Generator *this)
{
  if (this != NULL && this->label != NULL && this->alive)
    return 42;
  if (this == NULL)
    return 0;
  if (this->size != 0 || this->stack != NULL)
    {
      free(this->stack);
      this->stack = NULL;
      this->size = 0;
    }
  this->label = NULL;
  this->func = NULL;
  this->alive = 0;
  this->init = 0;
  return 0;
}

void		__yield_clean_up(Generator *this)
{
  if (this == NULL)
    return ;
  if (this->size != 0 || this->stack != NULL)
    {
      free(this->stack);
      this->stack = NULL;
      this->size = 0;
    }
  this->label = NULL;
  this->func = NULL;
  this->alive = 0;
  this->init = 0;
}
