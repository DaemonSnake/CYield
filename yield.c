#include <string.h>
#include <stdio.h>
#include "yield.h"

void		__yield_save_stack(Generator *this, const char *rsp, const char *rbp)
{
  size_t	i;

  this->size = rbp - rsp;
  if (this->buff != NULL)
    free(this->buff);
  this->buff = malloc(this->size);
  for (i = 0; i < this->size; i++)
    this->buff[i] = rsp[i];
}

void		__yield__pop_stack_back(Generator *this, const char *rsp)
{
  size_t	i;

  if (this == NULL || this->buff == NULL)
    return ;
  for (i = 0; i < this->size; i++)
    ((char *)(rsp))[i] = this->buff[i];
  free(this->buff);
  this->buff = NULL;
}

void		__yield__exit_error(void)
{
  fprintf(stderr,
	  "[ERROR]Calling Yielding function with non-re/set Generator\n");
  exit(-1);
}

void		reset_generator(Generator *this, void *addr)
{
  if (this->buff != NULL)
    free(this->buff);
  this->buff = NULL;
  this->size = 0;
  this->label = NULL;
  this->isNotEmpty = 42;
  this->funcId = addr;
}
