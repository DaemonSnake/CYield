# CYield
Implementation of the co-routine principle in C

For the people infamiliar with the idea. co-routines are functions that can be resumed after they returned.

A simple representation would be a follows:

A: calls B.
B: yields (returns) 42.
A: receive 42 and use it.
A: if B is not finished, resume function B.
B: resumes after the instruction yielding (returning) 42.
...

