import sys


# this should be a dp solution

# current_height
# max_height
# path_travelled
# optimal_solution
#

best_solution_height = 1002
best_solution_path = "IMPOSSIBLE"
#1000*41 

dp_list = []
distances = []

# table["UDUDUDUDU"] = 437

def spiderman(path_travelled, max_height, height, d_i):
    global best_solution_height
    global best_solution_path
    global dp_list
    
    if dp_list[max_height][d_i] != 0:
        # We have been here before
        return dp_list[max_height][d_i]
        
    elif len(distances) == d_i:
        if height - distances[0] == 0:
            #print("max_height = " + str(max_height) + " best_solution_height = " + str(best_solution_height))
            if max_height < best_solution_height:
                best_solution_height = max_height;
                best_solution_path = path_travelled + "D";
                #print("best_solution_path written to" + path_travelled + "D")
            return max_height;
        else:
            return "IMPOSSIBLE"
    
    up_result = "IMPOSSIBLE"
    up_max_height = max_height
    down_result = "IMPOSSIBLE"
    # Go up, only if it is better than current solution
    if height + distances[0] < best_solution_height:
        if height + distances[0] > max_height:
            #print("height = " + str(height) + " distances[0] = " + str(distances[0]) + " path = " + path_travelled + "U")
            up_max_height = height + distances[0]
        up_result = spiderman(path_travelled + "U", up_max_height, height + distances[0], distances[1:])
    # Go down, only if it does not go below street level
    if height - distances[0] >= 0:
        down_result = spiderman(path_travelled + "D", max_height, height - distances[0], distances[1:])
    #print("up_result = " + str(up_result) + " down_result = " + str(down_result))
    if up_result == "IMPOSSIBLE" and down_result == "IMPOSSIBLE":
        #print("1")
        return "IMPOSSIBLE"
    elif up_result == "IMPOSSIBLE":
        #print("2")
        return down_result
    elif down_result == "IMPOSSIBLE":
        #print("3")
        return up_result
    elif up_result < down_result:
        #print("4")
        return up_result
    else:
        #print("5")
        return down_result
    
    
def main():
    
    scenarios = int(sys.stdin.readline())
    global best_solution_height
    global best_solution_path
    global dp_list
    global distances
    
    while scenarios:
        best_solution_height = 1002
        best_solution_path = "IMPOSSIBLE"
        distances_size = int(sys.stdin.readline())
        distances = [int(x) for x in sys.stdin.readline().split()]
        dp_list = arr = [[0 for i in range(distances_size + 1)] for j in range(1000)]
        
        result = spiderman("", 0, 0, 0)
        print(best_solution_path)

            
        scenarios = scenarios - 1
    
    
    

if __name__ == "__main__":
    main()
