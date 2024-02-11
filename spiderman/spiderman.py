import sys

min_height = []
move_order = []
distances = []

inf = 1000000

def spiderman(distances_size, total_height):


    # Reset DP-board
    for i in range(distances_size):
        for j in range(total_height + 1):
            min_height[i][j] = inf
    
    # First step has to be U
    min_height[0][distances[0]] = distances[0]
    move_order[0][distances[0]] = 'U'

    # row by row, bottom to top
    for i in range(1, distances_size):
        for h in range(total_height + 1):

            # Is this state reachable?
            if (min_height[i - 1][h] != inf):
                # Can we go Down?
                if h >= distances[i]:
                    # Is this a better path?
                    # Either it is inf and we always want to replace it
                    # or the current path reaches the same state at a lower cost
                    if (min_height[i][h - distances[i]] > min_height[i - 1][h]):
                        min_height[i][h - distances[i]] = min_height[i-1][h]
                        move_order[i][h - distances[i]] = 'D'

                # Does going up increase our min height
                new_min_height = max(min_height[i - 1][h], h + distances[i])
                # Go Up
                # Either is is inf and we always want to replace it
                # or the current path reaches the same state at a lower cost
                if (min_height[i][h + distances[i]] > new_min_height):
                    min_height[i][h + distances[i]] = new_min_height
                    move_order[i][h + distances[i]] = 'U'
    
    # Search backwards for the solution
    if(min_height[distances_size - 1][0] == inf):
        print("IMPOSSIBLE")
    else:
        output = ""
        # start at floor level
        h = 0
        for i in range(distances_size - 1, -1, -1):
            output = move_order[i][h] + output
            if output[0] == 'U':
                h = h - distances[i]
            else:
                h = h + distances[i]
        print(output)



        
    
    
def main():
    
    scenarios = int(sys.stdin.readline())
    global distances
    global inf
    global min_height
    global move_order
    min_height = [[inf for i in range(1001)] for j in range(41)]
    move_order = [[inf for i in range(1001)] for j in range(41)]
    distances_size = 0
    
    while scenarios:

        distances_size = int(sys.stdin.readline())
        distances = [int(x) for x in sys.stdin.readline().split()]
        total = sum(distances)
        
        spiderman(distances_size, total)
            
        scenarios = scenarios - 1
    
    
    

if __name__ == "__main__":
    main()
