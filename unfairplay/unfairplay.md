# Problem Type
Maximum flow
# Proposed solution
Each team is represented by a node.
Each game is represented by a node.
The points flow from the source to the games, to the teams,
either granting one, two or zero flow, depending on match status.
Limit the flow of each team to sink so that it doesn't have more points than team N.
Team N is not represented by a node, it will win all it's matches, pre-calc the score.
Check that all matches have been played. It's possible to know before hand if team N
has lower score and plays in zero matches.

Check match status by looping through the finished graph
and checking flow from the match nodes to the team nodes

## Solution complexity
