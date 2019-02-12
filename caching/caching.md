# Problem Type
Decision problem
# Proposed solution

Greedy
Implement Belady's algorithm with a Map

Store the cache in a map, where the index of the next occurence is the key
and the element is the value.

If we have not stored the index

    if we have space look in the vector for it and load it
    into the cache with the next occurence as the value.

    if we do not have space since a Map is sorted on key
    we should easily find the largest or
    smallest element so we know which element to remove.

If we have stored the index, look in the vector for the next occurence
and replace the the key for that element with the new index.
## Solution complexity

## Special fall
c = 0
a = 0 checked

