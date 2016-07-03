# CYield
Implementation of the co-routine principle in C

For the people infamiliar with the idea. co-routines are functions that can be resumed after they returned.

A simple representation would be a follows:

A: calls B.</br>
B: yields (returns) 42.</br>
A: receive 42 and use it.</br>
A: if B is not finished, resume function B.</br>
B: resumes after the instruction yielding (returning) 42.</br>
...</br>
