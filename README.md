# Push_swap

## What is it?
This is an algorithmic project was done in School 21 (aka Ecole 42). 
The goal of this project is to sort stack (a) using another stack (b) with the following operations:

- sa (swap a): Swap the first 2 elements at the top of stack a.
  Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
  Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
  Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
  Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
  The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
  The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
  The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
  The last element becomes the first one.
- rrr : rra and rrb at the same time.

## How to launch?

Use ``make`` to build project. Pass unsorted stack to see operations that will sort it. Run ``./push_swap 2 1 3 6 5 8`` 
for examle.