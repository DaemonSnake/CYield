/*
  Copyright (c) 2015 Bastien Penavayre

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
#include "yield.h"

static __thread generator *__gen__ = 0;

int __yield_setjmp()
{
    if (!__gen__)
        return 0;
    __gen__->label = __builtin_return_address(0);
    __gen__->stop = 0;
    return 42;
}

void __yield_postjump()
{
    if (!__gen__)
        return ;
    __gen__->stop = 42;
    __gen__->label = 0;
}

generator *__yield_get_generator()
{
    return __gen__;
}

generator *__yield_update_generator(generator *val)
{
    __gen__ = val;
    return __gen__;
}

int __yield_continue(void *holder)
{
    ((generator**)holder)[2] = __gen__;
    __gen__ = ((generator**)holder)[0];
    return ((((generator**)holder)[1])->label != 0 && !(((generator**)holder)[1])->stop);
}