# Problem Type
Seems like a dijkstra with uniform cost (BFS should be sufficient)
where we want to list all the nodes with the longest distance
# Proposed solution
Keep a grid representing the chessboard.
    From start-position enumerate through the 8 possible moves for the knight
    add the nodes we haven't visited to the queue. Add nodes to visited
    pop-the queue from the front.

When loop finishes, loop through the chess board and add the nodes with the greatest distance to a string
and print them

You might be able to use the calculated matrix for every test-case 
## Solution complexity
