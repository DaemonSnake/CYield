/*
 * Copyright (C) 2015  Bastien Penavayre
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "yield.h"
#include <stdio.h>

yields(int) range(int b, int e)
{
    for (int i = b; i != e; i += (b < e ? 1 : -1))
        yield(i);
    yield_break(int);
}

yields(int) squareRange(int b, int e)
{
    for (int i = b; i != e; i += (b < e ? 1 : -1))
    {
        for_yield(ret, range(i, e))
            yield(ret);
        printf("\n");
    }
    yield_break(int);
}

int badFunction()
{
    yield(0);
    yield_break(int);
}

int main()
{
    for_yield(i, range(0, 5)) {
        printf("%d\n", i);
    }
    printf("\n");
    for_yield(i, range(5, 0)) {
        printf("%d\n", i);
    }
    printf("\n");
    for_yield(i, squareRange(0, 2))
        printf("%d\n", i);
    return 0;
}
