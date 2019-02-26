# Problem Type

Game theory
# Proposed solution

DP-table decision tree
seems like it could be too large
hard to know if it is the optimal solution
rather than the solution that gives
the highest total approval rather than maximizing
the wishes of a few

For each priest keep their satisfaction level as well as the resulting state
then traverse from top to bottom and flip according
to the vote until done.

# Current vote-state
Maximum size =  number of priests * number of states = 100 * 8 = 800 
     0 1 2 3 4 5 6 7 8
#  0 0 0 0 0 0 0 0 0 0
P  1 0
r  2 0
ä  3 0
s  4 0
t
med index


Understanding the rule that
always gives the best move for each priest

Flipping the 
left most bit if we want N
right most bit if we want Y

We want higher number?
     Flip right most bit that is not yes to yes
We want lower number ?
     Flip left most bit that is not no to no
If we are at desired state
     If desired state is low
          flip right most bit 
     If desired state is high
          flip left most bit  
## Solution complexity
