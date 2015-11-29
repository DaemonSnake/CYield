/*
** gctest.c for  in /home/penava_b/perso/test
**
** Made by penava_b
** Login   <penava_b@epitech.net>
**
** Started on  Sat Nov 28 02:32:38 2015 penava_b
** Last update Sun Nov 29 03:00:08 2015 penava_b
*/

#include <stdlib.h>
#include "yield.h"

int		__fake_setjmp(Generator *this)
{
  this->label = __builtin_return_address(0);
  return 0;
}

void		__yield_save_context(Generator *this, const char *rsp, const char *rbp)
{
  size_t       	i;

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

  if (this->stack == 0)
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
      "pop %rbp\n\t"
      "mov $0x42, %eax\n\t"
      "retq");
