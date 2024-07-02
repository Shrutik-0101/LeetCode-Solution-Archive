# Process
# Calculate node degrees:
# Assign importance values to nodes based on their degrees (number of connections).

# Assign importance values:
# Nodes with higher degrees get higher importance values.

# Maximize total importance:
# Sum up the importance values for all roads.

# Solution
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        f = [0 for _ in range(n)] 
        
        for x, y in roads:
            f[x] += 1
            f[y] += 1
        
        f.sort()
        s = 0
        for i in range(len(f)):
            s += f[i] * (i+1)  
        return s