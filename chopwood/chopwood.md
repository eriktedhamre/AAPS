# Problem Type
Graph problem
# Proposed solution
Take the input

The last element becomes the upper limit

Look through the V-list to determine which
nodes are eligible as leafs

Take the smallest of those nodes as the first leaf
Repeat but keep in mind that when a number
no longer appears in the V-list it should be added
to the eligible leaves.

priority queue for smallest leaf.
Map for if a number is eligible as a leaf

## Test Cases

Need a check to find if a tree is possible
for example is the
last number < number of cuts

How do you know if many such trees exist?


## Solution complexity

## Ideas
Since we cut off the smallest leaf first,
the last leaf left should be the largest.

This way we can know the largest element and
with the help of the V-list we know which elements
it can't be. 
So then we simply choose the smallest 
element not in the V-list that is less than the last element.