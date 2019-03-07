# Problem Type

Weighted graph with some blocked paths.

Don't think i need dijkstras since they are only going to ask one question.

Probably priority queue though


# Proposed solution
I assume george traverses the streets in the order they are listed
starting at time 0 and continuing instantly on the next street once he has finished one street.

This can be used to calculate where he is at all times.

Create a priority queue similar to dijkstra time table.

## Solution complexity
