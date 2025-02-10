from collections import defaultdict

def water_jug_solver(amt1, amt2, jug1, jug2, aim, visited):
    if (amt1 == aim and amt2 == 0) or (amt2 == aim and amt1 == 0):
        print(amt1, amt2)
        return True
    
    if visited[(amt1, amt2)] == False:
        print(amt1, amt2)
        visited[(amt1, amt2)] = True
        
        return (water_jug_solver(0, amt2, jug1, jug2, aim, visited) or
                water_jug_solver(amt1, 0, jug1, jug2, aim, visited) or
                water_jug_solver(jug1, amt2, jug1, jug2, aim, visited) or
                water_jug_solver(amt1, jug2, jug1, jug2, aim, visited) or
                water_jug_solver(amt1 + min(amt2, (jug1 - amt1)), amt2 - min(amt2, (jug1 - amt1)), jug1, jug2, aim, visited) or
                water_jug_solver(amt1 - min(amt1, (jug2 - amt2)), amt2 + min(amt1, (jug2 - amt2)), jug1, jug2, aim, visited))
    else:
        return False

# Initialize parameters
jug1, jug2, aim = 4, 3, 2
visited = defaultdict(lambda: False)

# Driver Code
print("Steps:")
water_jug_solver(0, 0, jug1, jug2, aim, visited)
